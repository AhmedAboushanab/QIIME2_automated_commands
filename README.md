# QIIME2_automated_commands
C++ commands to automate QIIME2 within a Linux Virtual Box

Compile each file in your favorite compiler WITHIN THE VIRTUAL BOX if not running QIIME2 naively 
  $ g++ (file).cpp
  $ ./a.out
  
Follow the keyboard input commands (cin)

## qiime_sort_raw.cpp

Demultiplexes and dereplicates raw fastq data (see notes at beginning of code)
***NOTE: dada2 in the QIIME2 environment runs much slower than dada2 in R

## qiime_files_convert.cpp

Converts abundnace table tab-delimited text file (.txt) to a biom file (.biom), then imports to QIIME2 as an artefact (.qza)
Creates summary directory for abundance table to determine maximum and minimum sampling depth
Imports FASTA representative set of sequences (.fasta) to QIIME2 as an artefact (.qza)

## qiime_arare_div.cpp

Inputs: abundance table (.qza), representative sequences (.qza), mapping file (.txt), maximum sampling depth (#), and rarefaction sampling depth (#)
QIIME2 commands run sequentially: 
  qiime diversity alpha-rarefaction
  qiime feature-table rarefy
  qiime alignment mafft
  qiime phylogeny fasttree
  qiime phylogeny midpoint-root (necessary for phylogenetic beta diversity)
  qiime diversity beta-phylogenetic
  qiime diversity pcoa
  qiime emperor plot
  
  export rarefied abundance table (.biom), convert to tab-delimited (.txt)
  export representative sequences 

## qiime_files_convert_2.cpp

  export rarefied abundance table (.biom), convert to tab-delimited (.txt)
  export representative sequences 

