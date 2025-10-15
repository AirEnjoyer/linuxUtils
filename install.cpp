#include <cstdlib>
#include <iostream>
#include <string>

void build(std::string &dirName) {
  system("rm -rf ../build/*");
  std::string buildCommand = "cmake ../";
  buildCommand += dirName;
  buildCommand += "/CMakeLists.txt && ninja";
  system(buildCommand.c_str());
}

void toBin(std::string &dirName) {
  std::string toBin = "sudo cp ";
  toBin += dirName;
  toBin += " /usr/local/bin";
  std::system(toBin.c_str());
}

int main(int argc, char *argv[]) {
  std::string dirName;
  if (argc > 1) {
    dirName = argv[1];
  } else {
    std::cout << "Enter the directory name" << std::endl;
    std::cin >> dirName;
  }

  build(dirName);
  toBin(dirName);
}
