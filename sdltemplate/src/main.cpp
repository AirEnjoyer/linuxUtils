#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string projectName;
  if (argc > 1) {
    projectName = argv[1];
  } else {
    while (projectName.empty()) {
      system("clear");
      std::cout << "Please enter the name for the project" << std::endl;
      std::cin >> projectName;
    }
  }
  std::ofstream CMakeLists("CMakeLists.txt");

  CMakeLists << "cmake_minimum_required(VERSION 3.7)" << std::endl << std::endl;

  CMakeLists << "project(" << projectName << " C CXX)" << std::endl
             << std::endl;

  CMakeLists << "set(CMAKE_CXX_STANDARD 20)" << std::endl;
  CMakeLists << "set(CMAKE_CXX_STANDARD_REQUIRED ON)" << std::endl;
  CMakeLists << "set(CMAKE_EXPORT_COMPILE_COMMANDS ON)" << std::endl;

  CMakeLists << "find_package(SDL3 REQUIRED)" << std::endl;
  CMakeLists << "find_package(OpenGL REQUIRED)" << std::endl;

  CMakeLists << "add_executable(${PROJECT_NAME} src/main.cpp)" << std::endl;

  CMakeLists << "target_include_directories(${PROJECT_NAME}" << std::endl;
  CMakeLists << "PRIVATE" << std::endl;
  CMakeLists << "${SDL3_INCLUDE_DIRS}" << std::endl;
  CMakeLists << "${CMAKE_CURRENT_SOURCE_DIR}/include" << std::endl;
  CMakeLists << ")" << std::endl;

  CMakeLists << "target_link_libraries(${PROJECT_NAME}" << std::endl
             << "PRIVATE" << std::endl
             << "SDL3::SDL3" << std::endl
             << "OpenGL::GL" << std::endl
             << ")" << std::endl;

  CMakeLists.close();
  std::system("mkdir build");
  std::system("mkdir src");
  std::system("mkdir headers");
  std::system("cp ~/src/main.cpp ./src/main.cpp");
  std::system("cmake -S . -B build/");

  return 0;
}
