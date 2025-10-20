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

  CMakeLists << "set(SOURCE_DIR \"${CMAKE_CURRENT_SOURCE_DIR}/src\")"
             << std::endl;
  CMakeLists << "file(GLOB SOURCE_FILES \"${SOURCE_DIR}/*.cpp\")" << std::endl;

  CMakeLists << "add_library(glad STATIC" << std::endl;
  CMakeLists << "glad/src/glad.c" << std::endl;
  CMakeLists << ")" << std::endl;
  CMakeLists << "target_include_directories(glad PUBLIC glad/include)"
             << std::endl;

  CMakeLists << "add_executable(${PROJECT_NAME} ${SOURCE_FILES})" << std::endl;

  CMakeLists << "target_include_directories(${PROJECT_NAME}" << std::endl;
  CMakeLists << "PRIVATE" << std::endl;
  CMakeLists << "${SDL3_INCLUDE_DIRS}" << std::endl;
  CMakeLists << "glad/include" << std::endl;
  CMakeLists << "${CMAKE_CURRENT_SOURCE_DIR}/include" << std::endl;
  CMakeLists << ")" << std::endl;

  CMakeLists << "target_link_libraries(${PROJECT_NAME}" << std::endl
             << "PRIVATE" << std::endl
             << "glad" << std::endl
             << "${SDL3_LIBRARIES}" << std::endl
             << "OpenGL::GL" << std::endl
             << ")" << std::endl;

  CMakeLists.close();
  std::system("cp -r ~/glad ./");
  std::system("mkdir build");
  std::system("mkdir src");
  std::system("mkdir headers");

  std::ofstream main("src/main.cpp");
  main << "#include <SDL3/SDL.h>" << std::endl
       << "#include <glad/glad.h>" << std::endl;
  main << "#include <iostream>" << std::endl << std::endl;
  main << "int main() {" << std::endl
       << "int x = 0;" << std::endl
       << "return 0;" << std::endl
       << "}" << std::endl;
  main.close();

  return 0;
}
