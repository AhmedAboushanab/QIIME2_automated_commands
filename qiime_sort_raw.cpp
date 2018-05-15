//need to extract barcodes in QIIME 1 (extract_barcodes.py)
//need to correct mapping file in QIIME 1 (validate_mapping_file.py)
//name "barcodes.fastq"
//rename raw reads "forward.fastq" and "reverse.fastq"
//need mapping file named "_full_mapping_corrected.txt"
//base memory needs to be AT LEAST 1/3 of full computer's capacity



#include <iostream>
#include <string>
#include <cstdlib>

int main() {

  std::string f, m;
  std::string m_f, m_r, n_f, n_r;

  std::cout << "The project name is (no filetype): ";
  std::cin >> f;

  std::cout << "Mapping file is (include filename): ";
  std::cin >> m;

  std::cout << "Nucleotide position to truncate, forward (5'): ";
  std::cin >> m_f;
  std::cout << "Nucleotide position to truncate, reverse (5'): ";
  std::cin >> m_r;
  std::cout << "N nucleotide to trim at beginning, forward (3'): ";
  std::cin >> n_f;
  std::cout << "N nucleotide to trim at beginning, reverse (3'): ";
  std::cin >> n_r;

  std::string command_zip1 = "gzip "+f+"_paired_end/barcodes.fastq";
  std::string command_zip2 = "gzip "+f+"_paired_end/forward.fastq";
  std::string command_zip3 = "gzip "+f+"_paired_end/reverse.fastq";
  std::system(command_zip1.c_str());
  std::system(command_zip2.c_str());
  std::system(command_zip3.c_str());
  std::cout<< "Fastq files have been zipped \n";

  std::string command_import = "qiime tools import --type EMPPairedEndSequences --input-path "+
                                f+"_paired_end/"+
                                " --output-path "+f+"_paired_end.qza";
  std::system(command_import.c_str());
  std::cout << "Raw reads have been imported \n";

  std::string command_demux_paired = "qiime demux emp-paired --i-seqs "+
                                      f+"_paired_end.qza --m-barcodes-file "+
                                      m+" --m-barcodes-category BarcodeSequence --verbose --o-per-sample-sequences "+
                                      f+"_paired_demux.qza";
  std::system(command_demux_paired.c_str());
  std::cout << "Raw reads have been demultiplexed \n";

  std::string command_denoise_paired = "qiime dada2 denoise-paired --i-demultiplexed-seqs "+
                                        f+"_paired_demux.qza --p-trunc-len-f "+
                                        m_f+" --p-trunc-len-r "+
                                        m_r+" --p-trim-left-f "+
                                        n_f+" --p-trim-left-r "+
                                        n_r+" --verbose --o-table "+
                                        f+"_paired_demux_dada_table.qza --o-representative-sequences "+
                                        f+"_paired_demux_dada_rep_seq.qza";
  std::system(command_denoise_paired.c_str());
  std::cout << "Raw reads have been joined and filtered. \n 'OTU' table and rep set have been created \n";



}
