#!/usr/bin/perl

use strict;
use warnings;
use v5.14;

use FindBin;
chdir $FindBin::Bin;

use File::Copy;
use File::Path qw(remove_tree);

use Getopt::Long;

use constant {
    TRUE  => 1,
    FALSE => 0,
    V_LOW_PRIO => 5,
    V_MED_PRIO => 3,
    V_HIGH_PRIO => 1
};

my $make_usubac = FALSE; # If true, then recompile Usubac (implies --generate)
my $generate    = FALSE; # If true, then regenerate the C sources from Usuba
my $verbose     = V_LOW_PRIO;
my $run_benchs  = FALSE; # If true, run the benchmarks
my $collect     = TRUE ; # If true, collects the data from the benchmakrs

GetOptions('make-usubac' => sub { $make_usubac = $generate = 1 },
           'generate'    => \$generate,
           'verbose=i'   => \$verbose,
           'run-benchs'  => \$run_benchs,
           'collect'     => \$collect);


sub status {
    my $priority = shift;
    if ($verbose >= $priority) {
        say @_;
    }
}
our $job_str = ''; # Don't pay attention, I'm gonna play with dynamic scoping :p
sub status_start { status(V_HIGH_PRIO, "$job_str: in progress...") }
sub status_end   { status(V_HIGH_PRIO, "$job_str: done.") }




# Generation of the C ciphers
make_usubac() if $make_usubac;
generate() if $generate;

# Running supercop benchmarks
run_benchs() if $run_benchs;

# Collecting the results
collect() if $collect;




sub make_usubac {
    local $job_str = "Recompiling Usubac";
    status_start;
    
    die "Couldn't make." if system 'make';
    
    status_end;
}


sub generate {
    local $job_str = "Regenerating C ciphers from Usuba";
    status_start;

    my $options_all = '-no-share -no-runtime';

    my %conf = (
        aes       => { src => 'aes_kasper.ua', archs => [qw(sse avx)], 
                       dir => 'aes128ctr', opts => ' '  },
        rectangle => { src => 'rectangle.ua', archs => [qw(sse)], 
                       dir => 'rectangle64ctr', opts => ' ' },
        serpent   => { src => 'serpent.ua', archs => [qw(std sse avx)], 
                       dir => 'serpent128ctr', opts => '-bits-per-reg 32' },
        chacha20  => { src => 'chacha20.ua',archs => [qw(std sse avx)],  
                       dir => 'chacha20', opts => '-bits-per-reg 32' });

    while (my ($cipher,$cconf) = each %conf) {
        status(V_MED_PRIO, "Generating $cipher...");
        for my $arch (@{$cconf->{archs}}) {
            status(V_LOW_PRIO, "Generating ${cipher}::${arch}...");

            my $dst_dir = "supercop/crypto_stream/$cconf->{dir}/usuba-$arch/";
            
            # Compiling the Usuba cipher to C
            die "Couldn't compile '$cipher -- $arch'" if 
                system "./usubac "
                . "-o $dst_dir/$cipher.c "
                . "$options_all "
                . "$cconf->{opts} "
                . "-arch $arch "
                . "samples/usuba/$cconf->{src}";

            # Making sure the arch specific header is up-to-date
            copy "arch/" . uc($arch) . ".h", $dst_dir;
            
            status(V_LOW_PRIO, "Generating ${cipher}::${arch}: done.");
        }
        status(V_MED_PRIO, "Generating $cipher: done.");
    }
    
    status_end;
}

sub run_benchs {
    local $job_str = "Running Supercop (this could take a while)";
    status_start;

    remove_tree "supercop-data";
    chdir "supercop";
    unlink "supercop-data";
    
    die "Error in supercop benchmark." if system "./data-do";

    local $job_str = "Running Supercop";
    status_end;
}


sub collect {
    local $job_str = "Collecting results";
    status_start;

    
    #supercop-data/dadavm/amd64/try/c/
    

    status_end;
}
