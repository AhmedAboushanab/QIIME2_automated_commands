#include <iostream>
#include <string>
#include <cstdlib>


int main() {


  std::string f;

  std::cout << "The feature table is (no filetype): ";
  std::cin >> f;

  std::string command = "qiime tools export "+f+"_even.qza --output-dir "+f+"_even_export";
  std::system(command.c_str());

  std::string command1 = "biom convert -i "+f+"_even_export/feature-table.biom -o "+f+"_even_from_biom.txt --to-tsv";
  std::system(command1.c_str());



}
