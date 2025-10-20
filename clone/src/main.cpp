#include <cstdlib>
#include <iostream>
#include <string>

void getRepo(std::string &clone) {
  std::cout << "Enter the author name and repo name (eg. sindresorhus/awesome)"
            << std::endl;
  std::string repo;
  std::cin >> repo;
  clone += repo;
}

int main(int argc, char *argv[]) {
  std::string clone = "git clone --depth 1 --branch ";
  // main --single-branch https://github.com/";
  if (argc == 2) {
    std::cout << "Using default branch main, add branch after repo to use a "
                 "different one"
              << std::endl;
    clone += "main --single-branch https://github.com/";
    clone += argv[1];
  } else if (argc == 3) {
    clone += argv[2];
    clone += " --single-branch https://github.com/";
    clone += argv[1];
  } else {
    std::cout << "Usage: clone Author/repoName " << std::endl
              << "Optionally, do Author/repoName branch to use a branch other "
                 "than main"
              << std::endl;
    exit(1);
  }
  system(clone.c_str());

  return 0;
}
