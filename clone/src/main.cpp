#include <iostream>
#include <cstdlib>
#include <string>

void getRepo(std::string &clone){
    std::cout << "Enter the author name and repo name (eg. sindresorhus/awesome)" << std::endl;
    std::string repo;
    std::cin >> repo;
    clone += repo;
}

int main(int argc, char *argv[]) {
    std::string clone = "git clone --depth 1 --branch main --single-branch https://github.com/"; 
    if (argc > 1){
        clone += argv[1];
    } else {
        getRepo(clone);
    }
    system(clone.c_str());

return 0;
}
