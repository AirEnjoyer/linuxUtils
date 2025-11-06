#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  std::string cloneCommand = "git clone --depth 1 ";
  if (argc == 2) {
    std::string arg2 = argv[1];
    if (arg2 != "ssh" && arg2 != "https") {
      std::cout << "Using https, to use ssh use \" clone ssh owner/repo.git\""
                << std::endl;
      cloneCommand += arg2;
    } else if (arg2 == "https" | arg2 == "ssh") {
      std::cerr << arg2 << " requires a repo \n";
      return 1;
    }
  } else if (argc == 3) {
    std::vector<std::string> args(argv, argv + argc);
    if (args[1] == "ssh") {
      cloneCommand += "git@github.com:";
    } else if (args[1] == "https") {
      cloneCommand += "https://github.com/";
    }
    cloneCommand += args[2];
  } else if (argc == 1) {
    std::cerr << "clone requires arguments. Usage: clone <method> (method can "
                 "be ssh or https) owner/repo.git";
    return 1;
  }
  std::system(cloneCommand.c_str());

  return 0;
}
