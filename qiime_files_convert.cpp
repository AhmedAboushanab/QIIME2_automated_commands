//to be run in Virtual Box with qiime2 VB image loaded with command line interface
//converts txt-->biom-->qza

#include <iostream>
#include <string>
#include <cstdlib>

int main() {

  std::string f, n, r;

  std::cout << "The OTU table is (no filetype): ";
  std::cin >> f;

  std::cout << "The rep set of sequences is (no filetype): ";
  std::cin >> r;

  std::string command = "biom convert -i "+f+".txt"+" -o "+f+".biom"+
                        " --to-hdf5 --table-type='OTU table'";

  std::system(command.c_str());
  std::cout<<"Biom file created \n";

  std::string command1 = "qiime tools import --input-path "+f+".biom"+
                          " --type 'FeatureTable[Frequency]' --source-format BIOMV210Format --output-path "
                          +f+".qza";

  std::system(command1.c_str());
  std::cout<<"Qza file created \n";


  std::string command3 = "qiime feature-table summarize --i-table "+f+".qza"+
  " --output-dir "+f;
//creates summary directory

//metadata option
//"--m-sample-metadata-file"+f+"_metadata.txt"

  std::system(command3.c_str());
  std::cout<<"Summary directory created \n" <<"Need to unzip qzv in VirtualBox\n";

  std::string command4 = "qiime tools import --input-path "+r+".fa"+
  " --output-path "+r+".qza"+
  " --type 'FeatureData[Sequence]'";

  std::system(command4.c_str());
  std::cout<<"Rep set of sequences has been converted to qza \n";

  return 0;

}
