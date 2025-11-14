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
    std::system("mkdir src");

    std::ofstream main("src/main.cpp");

    main << "#include <SDL3/SDL.h>" << "\n"
         << "#include <iostream>" << "\n"
         << "\n";

    main
        << "SDL_Window *CreateWindow(const char *title, int width, int height,"
        << "\n"
        << "Uint32 flags){" << "\n"
        << "SDL_Window *window = SDL_CreateWindow(title, width, height, flags);"
        << "\n"
        << "return window;" << "\n"
        << "}" << "\n"
        << "\n";

    main << "SDL_Renderer *CreateRenderer(SDL_Window *window){" << "\n"
         << "SDL_Renderer *renderer= SDL_CreateRenderer(window, nullptr);"
         << "\n"
         << "return renderer;" << "\n"
         << "}" << "\n"
         << "\n";

    main << "void MainLoop(SDL_Renderer *renderer){" << "\n"
         << "bool running = true;" << "\n"
         << "SDL_Event event;" << "\n"
         << "while (running) {" << "\n"
         << "while (SDL_PollEvent(&event)) {" << "\n"
         << "if (event.type == SDL_EVENT_QUIT) {" << "\n"
         << "running = false;" << "\n"
         << "}" << "\n"
         << "}" << "\n";

    main << "SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);" << "\n"
         << "SDL_RenderClear(renderer);" << "\n"
         << "SDL_RenderPresent(renderer);"
            "\n"
         << "}" << "\n"
         << "}" << "\n";

    main << "void CleanUp(SDL_Window *window, SDL_Renderer *renderer) {"
            "\n"
         << "SDL_DestroyRenderer(renderer);" << "\n"
         << "SDL_DestroyWindow(window);" << "\n"
         << "SDL_Quit();" << "\n"
         << "}" << "\n"
         << "\n";

    main << "int main (int argc, char *argv[]) {"
            "\n"
         << "if  (!SDL_Init(SDL_INIT_VIDEO)) {" << "\n"
         << "std::cout << SDL_GetError() << std::endl;" << "\n"
         << "}" << "\n"
         << "\n"
         << "SDL_Window *window = CreateWindow(\"window\", 640, 480, "
            "SDL_WINDOW_RESIZABLE);"
         << "\n"
         << "SDL_Renderer *renderer = CreateRenderer(window);" << "\n"
         << "\n"
         << "\n"
         << "MainLoop(renderer);" << "\n"
         << "CleanUp(window, renderer);" << "\n"
         << "\n"
         << "\n"
         << "return 0;"
         << "}";
    main.close();

    std::ofstream CMakeLists("CMakeLists.txt");

    CMakeLists << "cmake_minimum_required(VERSION 3.25)" << std::endl
               << std::endl;

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
    std::system("mkdir headers");
    std::system("cmake -S . -B build/ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON");

    return 0;
}
