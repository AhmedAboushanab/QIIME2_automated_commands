# QIIME2_automated_commands
C++ commands to automate QIIME2 within a Linux Virtual Box  <br />
 <br />
Compile each file in your favorite compiler WITHIN THE VIRTUAL BOX if not running QIIME2 naively  <br />
  $ g++ (file).cpp  <br />
  $ ./a.out  <br />
  
  
Follow the keyboard input commands (cin)

## qiime_sort_raw.cpp

Demultiplexes and dereplicates raw fastq data (see notes at beginning of code)  <br />
***NOTE: dada2 in the QIIME2 environment runs much slower than dada2 in R

## qiime_files_convert.cpp

Converts abundnace table tab-delimited text file (.txt) to a biom file (.biom), then imports to QIIME2 as an artefact (.qza)  <br />
Creates summary directory for abundance table to determine maximum and minimum sampling depth  <br />
Imports FASTA representative set of sequences (.fasta) to QIIME2 as an artefact (.qza)  <br />

## qiime_arare_div.cpp

Inputs: abundance table (.qza), representative sequences (.qza), mapping file (.txt), maximum sampling depth (#), and rarefaction sampling depth (#)
 <br />
QIIME2 commands run sequentially:  <br />
  &nbsp; qiime diversity alpha-rarefaction <br />
  &nbsp; qiime feature-table rarefy <br />
  &nbsp; qiime alignment mafft  <br />
  &nbsp; qiime phylogeny fasttree  <br />
  &nbsp; qiime phylogeny midpoint-root (necessary for phylogenetic beta diversity)  <br />
  &nbsp; qiime diversity beta-phylogenetic  <br />
  &nbsp; qiime diversity pcoa  <br />
  &nbsp; qiime emperor plot  <br />
  
  &nbsp; export rarefied abundance table (.biom), convert to tab-delimited (.txt)  <br />
  &nbsp; export representative sequences 

## qiime_files_convert_2.cpp

  &nbsp; export rarefied abundance table (.biom), convert to tab-delimited (.txt) <br />
  &nbsp; export representative sequences 

