#include <cstdlib>
#include <iostream>
#include <string>

void toBin(std::string path) {
  std::string toBin = "cp ";
  toBin += path;
  toBin += " /usr/local/bin";
  std::system(toBin.c_str());
}

int main(int argc, char *argv[]) {
  std::string path;
  if (argc > 1) {
    path = argv[1];
  } else {
    std::cout << "Enter the path to the executable: " << std::flush;
    std::cin >> path;
  }
  toBin(path);
  return 0;
}
