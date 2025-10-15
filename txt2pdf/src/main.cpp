#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
  std::string sourcePath = argv[1];
  std::string toPS = "enscript -p ~/.cache/temp.ps " + sourcePath;
  std::cout << toPS << std::endl;
  system(toPS.c_str());
  std::string endPath = argv[2];
  std::string toPDF = "ps2pdf ~/.cache/temp.ps " + endPath;
  system(toPDF.c_str());
  system("rm ~/.cache/temp.ps");
  return 0;
}
