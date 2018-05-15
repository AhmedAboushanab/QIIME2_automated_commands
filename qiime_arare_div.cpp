//to be run in Virtual Box with qiime2 VB image loaded with command line interface
//alpha diversity, rarefaction, rep set seq align, phylo tree, beta div distance matrix, pcoa
//NEED TO HAVE OTU sample summary, converted OTU table, and rep set

#include <iostream>
#include <string>
#include <cstdlib>

int main() {

  std::string f, n1, n2, r, m;


  std::cout << "The OTU table is (no filetype): ";
  std::cin >> f;

  std::cout << "The rep set of sequences is (no filetype): ";
  std::cin >> r;

  std::cout << "The mapping file is (with filetype): ";
  std::cin >> m;

  std::cout << "Max sampling depth: ";
  std::cin >> n1;

  std::cout << "Rarefaction sampling depth: ";
  std::cin >> n2;

    std::string command_alpha = "qiime diversity alpha-rarefaction --i-table "+f+".qza"+
                        " --p-metrics observed_otus  --output-dir "+f+"_arare"+
                        " --p-max-depth " + n1;

    std::system(command_alpha.c_str());
    std::cout<<"Alpha rarefaction directory created \n";

    std::string command_rare = "qiime feature-table rarefy --i-table "+f+".qza"+
                          " --p-sampling-depth " + n2+
                          " --o-rarefied-table " +f+"_even";

    std::system(command_rare.c_str());
    std::cout<<"Rarefied table created \n";

    std::string command_align = "qiime alignment mafft --i-sequences "+r+".qza"+
                            " --o-alignment "+r+"_aligned --verbose";

    std::system(command_align.c_str());
    std::cout<<"Rep set of sequences has been aligned with MAFFT \n";


//beta diversity

      std::string command_tree = "qiime phylogeny fasttree --i-alignment "+r+"_aligned.qza"+
                              " --o-tree "+f+"_even_aligned_tree --verbose";
      std::system(command_tree.c_str());
      std::cout<<"Phylogenetic tree has been created \n";

      std::string command_root = "qiime phylogeny midpoint-root --i-tree "+f+"_even_aligned_tree.qza"+
                              " --o-rooted-tree "+f+"_even_aligned_tree_rooted.qza --verbose";
      std::system(command_root.c_str());
      std::cout<<"Phylogenetic tree has been rooted \n";

      std::string command_beta = "qiime diversity beta-phylogenetic --i-table "+f+"_even.qza "+
                              "--i-phylogeny "+f+"_even_aligned_tree_rooted.qza "+
                              "--p-metric weighted_unifrac --output-dir "+f+"_even_beta_div --verbose";
      std::system(command_beta.c_str());
      std::cout<<"Weighted Unifac distance matrix has been created \n";


      std::string command_pcoa = "qiime diversity pcoa --i-distance-matrix "+f+"_even_beta_div/distance_matrix.qza"+
                              " --output-dir "+f+"_even_pcoa --verbose";
      std::system(command_pcoa.c_str());
      std::cout<<"PCoA directory has been created \n";

      std::string command_pcoa_viz = "qiime emperor plot --i-pcoa "+
                                      f+"_even_pcoa/pcoa.qza --m-metadata-file "+
                                      m+" --o-visualization "+f+"_even_pcoa_viz.qzv";
      std::system(command_pcoa_viz.c_str());
      std::cout << "PCoA visualization has been created \n";



      std::string command_export = "qiime tools export "+f+"_even.qza --output-dir "+f+"_even_export";
      std::system(command_export.c_str());

      std::string command_txt = "biom convert -i "+f+"_even_export/feature-table.biom -o "+
                              f+"_even_from_biom.txt --to-tsv";
      std::system(command_txt.c_str());
      std::cout << "Rarefied feature table has been converted to text file \n";

      std::string command_export1 = "qiime tools export "+r+".qza --output-dir "+f+"_rep_set_export";
      std::system(command_export1.c_str());
      std::cout << "Rep set of sequences has been exported as a fasta file \n";


  return 0;



}
