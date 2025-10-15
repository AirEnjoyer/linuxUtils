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

  CMakeLists << "cmake_minimum_required(VERSION 4.0)" << std::endl;
  CMakeLists << "cmake_policy(set cmp0072 new)" << std::endl << std::endl;

  CMakeLists << "project(" << projectName << " C CXX)" << std::endl
             << std::endl;

  CMakeLists << "set(CMAKE_CXX_STANDARD 20)" << std::endl;
  CMakeLists << "set(CMAKE_CXX_STANDARD_REQUIRED ON)" << std::endl;
  CMakeLists << "set(CMAKE_EXPORT_COMPILE_COMMANDS ON)" << std::endl
             << std::endl;

  CMakeLists << "find_package(SDL2 REQUIRED)" << std::endl
             << "find_package(OpenGL REQUIRED)" << std::endl
             << std::endl;

  CMakeLists << "set(SOURCE_DIR \"${CMAKE_CURRENT_SOURCE_DIR}/src\")"
             << std::endl;
  CMakeLists << "file(GLOB SOURCE_FILES \"${SOURCE_DIR}/*.cpp\")" << std::endl
             << std::endl;
  CMakeLists
      << "add_library(glad STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)"
      << std::endl;
  CMakeLists << "target_include_directories(glad PUBLIC "
                "\"${CMAKE_CURRENT_SOURCE_DIR}/include\")"
             << std::endl;
  CMakeLists << "set_target_properties(glad PROPERTIES LINKER_LANGUAGE C)"
             << std::endl;
  CMakeLists << "add_executable(${PROJECT_NAME} ${SOURCE_FILES})" << std::endl
             << std::endl;

  CMakeLists << "target_include_directories(${PROJECT_NAME}" << std::endl
             << "PRIVATE" << std::endl
             << "${SDL2_INCLUDE_DIRS}" << std::endl
             << ")" << std::endl;

  CMakeLists << "target_link_libraries(${PROJECT_NAME}" << std::endl
             << "PRIVATE" << std::endl
             << "glad" << std::endl
             << "${SDL2_LIBRARIES}" << std::endl
             << "${CMAKE_CURRENT_SOURCE_DIR}/include" << std::endl
             << "OpenGL::GL" << std::endl
             << ")" << std::endl;

  CMakeLists.close();
  system("mkdir include");
  system("cp ~/glad/include/glad/glad.h include/");
  system("cp ~/glad/include/KHR/khrplatform.h include/");
  system("cp ~/glad/src/glad.c include/");
  system("mkdir build");
  system("mkdir src");
  system("mkdir headers");

  std::ofstream main("src/main.cpp");
  main << "#include <SDL2/SDL.h>" << std::endl
       << "#include <glad/glad.h>" << std::endl;
  main << "#include <iostream>" << std::endl << std::endl;
  main << "int main() {" << std::endl
       << "int x = 0;" << std::endl
       << "return 0;" << std::endl
       << "}" << std::endl;
  main.close();

  return 0;
}
