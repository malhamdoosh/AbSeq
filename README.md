# Table of contents
* [Introduction](#introduction)
    * [AbSeq](#abseq)
    * [Developers](#developers)
* [Prerequisites](#prerequisites)
    * [Seamless installation of dependencies](#seamless-installation-of-dependencies)
    * [Manual installation of dependencies](#manual-installation-of-dependencies)
* [abseqPy Installation](#abseqpy-installation)
    * [Install from `pip`](#install-from-pip)
    * [Install from source](#install-from-source)
* [Usage](#usage)
    * [Basic usage](#basic-usage)
    * [Advanced usage](#advanced-usage)
    	* [Gotchas](#gotchas)
    * [Help](#help)
* [Supported platforms](#supported-platforms)

# Introduction

## AbSeq
`AbSeq` is a comprehensive bioinformatic pipeline for the analysis of sequencing datasets generated from antibody libraries and `abseqPy` is one of its packages. Given FASTQ or FASTA files (paired or single-ended), `abseqPy`
_generates clonotypes tables_, _V-(D)-J germline annotations_, _functional rates_, and
_diversity estimates_ in a combination of csv and HDF files. More specialized analyses for antibody libraries
like _primer specificity_, _sequence motif analysis_, and _restriction sites analysis_ are also on the list.

This program is intended to be used in conjunction with [`abseqR`](https://github.com/malhamdoosh/abseqR),
a reporting and statistical analysis package for the data generated by `abseqPy`. Although `abseqPy` works fine _without_ `abseqR`, it is highly recommended that users also install the R package in order to take the advantage of the interactive HTML reporting capabilities of the pipeline. `abseqR`'s project page shows a few [examples](https://github.com/malhamdoosh/abseqR#features) of the type of analysis `AbSeq` provides; the full documentation can be found in `abseqR`'s vignette.

## Developers
* `AbSeq` is developed by Monther Alhamdoosh and JiaHong Fong
* For comments and suggestions, email m.hamdoosh \<at\> gmail \<dot\> com


# Prerequisites

`abseqPy` depends on a few external software to work and they should be properly
installed and configured before running `abseqPy`.

> `abseqPy` runs on Python 2.7. Python 3.6 support is underway.


## Seamless installation of dependencies 

This is the __recommended way__ of installing abseqPy's external dependencies.

A python script is available [here](install_dependencies.py) which downloads and installs all the necessary external dependencies.

This script assumes the following is already available:
* [perl](https://www.perl.org/get.html)
* [git](https://git-scm.com/)
* [python](https://www.python.org)
* [Java JRE](http://www.oracle.com/technetwork/java/javase/downloads/jre8-downloads-2133155.html) version 1.6 or higher
* [C/C++ compilers](https://gcc.gnu.org/) (not required for Windows)
* [make](https://en.wikipedia.org/wiki/Make_(software)) (not required for Windows)
* [CMake](https://cmake.org/) (not required for Windows)

To install external dependencies into a folder named `~/.local/abseq`:

```bash
$ mkdir -p ~/.local/abseq
$ python install_dependencies.py ~/.local/abseq
```

> This script does _not_ install `abseqPy` itself, only its external dependencies.

This script works with Python 2 and 3, and `~/.local/abseq` can be replaced with any directory.
However:
* this directory will be there to stay, so choose wisely
* the installation script will dump more than just binaries in this directory, it will contain databases and internal files
 
as soon as the installation succeeds, users will be prompted with an onscreen message
to update their environment variables to include installed dependencies in `~/.local/abseq`.

## Manual installation of dependencies

This section is for when one:

1. finds that the installation script failed
2. is feeling adventurous

refer to [this document](DEPS_INSTALL.md) for a detailed guide.


# abseqPy installation

This section demonstrates how to install `abseqPy`.

## Install from `pip`

```bash
$ pip install abseqPy
```

## Install from source

```bash
$ git clone https://github.com/malhamdoosh/abseqPy.git
$ cd abseqPy
$ pip install .
$ abseq --version
```

The `abseq` command should now be available on your command line.

> installing `abseqPy` also installs other python packages, consider using a python virtual environment to prevent 
overriding existing packages. See [virtualenv](https://packaging.python.org/guides/installing-using-pip-and-virtualenv/)
or [conda](https://conda.io/docs/user-guide/tasks/manage-environments.html).


# Usage

## Basic usage

To get up and running, the following command is often sufficient:

```bash
$ abseq -f1 <read 1> -f2 <read 2> -o results --threads 4 --task all
```

`-f2` is only required if it is a paired-end sequencing experiment.


### Advanced usage

Besides calling `abseq` with command line options, `abseq` also supports `-y <file>` or `--yaml <file>` 
that reads parameters defined in `file`. This enables multiple samples to be analyzed at the same time, each
having shared or independent `abseq` parameters.

The basic YAML syntax of `file` is `key: val` where `key `is an `abseq`
"long"<sup name="sup1">[1](#foot1)</sup> option (see `abseq --help` for all the "long" option names) and
`val` is the value supplied to the "long" option. Additional samples are specified one after another
separated by triple dashes `---`.


###### Example
Assuming a file named `example.yml` has the following content:

```yaml
# sample one, PCR1
name: PCR1
file1: fastq/PCR1_R1.fastq.gz
file2: fastq/PCR1_R2.fastq.gz
---
# sample two, PCR2
name: PCR2
file1: fastq/PCR2_R1.fastq.gz
file2: fastq/PCR2_R2.fastq.gz
bitscore: 300                 # override the defaults' 350 for this sample only
task: abundance               # override the defaults' "all" for this sample only
detailedComposition: ~        # enables detailedComposition (-dc) for this sample only
---
# more samples can go here
---
# "defaults" is the only special key allowed.
# It is not in abseq's options, but is used here
# to denote default values to be used for ALL samples
# if they're not specified.
defaults:
    task: all
    outdir: results
    threads: 7
    bitscore: 350
    sstart: 1-3
```

then executing `abseq -y example.yml` is equivalent to simultaneously running 2 instances of
`abseq` with the parameters in the `defaults` field applied to both samples. Here's an
equivalent:

```bash
$ abseq --task all --outdir results --threads 7 --bitscore 350 --sstart 1-3 \
>   --name PCR1 --file1 fastq/PCR1_R1.fastq.gz --file2 fastq/PCR1_R2.fastq.gz
$ abseq --task abundance --outdir results --threads 7 --bitscore 300 --sstart 1-3 \
>   --name PCR2 --file1 fastq/PCR2_R1.fastq.gz --file2 fastq/PCR2_R2.fastq.gz \
>   --detailedComposition 
```
Using `--yaml` is recommended because it is self-documenting, reproducible, and simple to run.

### Gotchas

1. In the above example, specifying `threads: 7` in the `defaults` key of `example.yml` will run _each_ sample with
7 threads, that is, `abseqPy` will be running with 7 * `number of samples` total processes.

## Help

Invoking `abseq -h` in the command line will display the options `abseqPy` uses.

# Supported platforms

`abseqPy` works on most Linux distros, macOS, and Windows.

Some features are *disabled* when running in *Windows* due to software incompatibility, they are:

* Upstream clustering in `--task 5utr`
* Sequence logo generation in `--task diversity`

---

<small><b id="foot1">1</b></small><small> long option names are option names with a double dash prefix, for example,
`--help` is a long option while `-h` is not [↩](#sup1)</small>
