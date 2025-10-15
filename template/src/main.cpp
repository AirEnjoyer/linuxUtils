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

  CMakeLists << "cmake_minimum_required(VERSION 4.0)" << std::endl << std::endl;

  CMakeLists << "project(" << projectName << " C CXX)" << std::endl
             << std::endl;

  CMakeLists << "set(CMAKE_CXX_STANDARD 20)" << std::endl;
  CMakeLists << "set(CMAKE_CXX_STANDARD_REQUIRED ON)" << std::endl;
  CMakeLists << "set(CMAKE_EXPORT_COMPILE_COMMANDS ON)" << std::endl
             << std::endl;

  CMakeLists << "set(SOURCE_DIR \"${CMAKE_CURRENT_SOURCE_DIR}/src\")"
             << std::endl;
  CMakeLists << "file(GLOB SOURCE_FILES \"${SOURCE_DIR}/*.cpp\")" << std::endl
             << std::endl;
  CMakeLists << "add_executable(${PROJECT_NAME} ${SOURCE_FILES})" << std::endl
             << std::endl;

  CMakeLists << "target_include_directories(" << projectName
             << " PUBLIC \"${CMAKE_CURRENT_SOURCE_DIR}/include\")";

  CMakeLists.close();
  system("mkdir build");
  system("mkdir src");
  system("mkdir headers");

  std::ofstream main("src/main.cpp");
  main << "#include <iostream>" << std::endl << std::endl;
  main << "int main() {" << std::endl
       << "int x = 0;" << std::endl
       << "return 0;" << std::endl
       << "}" << std::endl;
  main.close();

  return 0;
}
