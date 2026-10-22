cmake_minimum_required(VERSION 3.16)
project(JogoTecProg CXX)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)      # SFML estático: sem DLLs do SFML
set(SFML_BUILD_AUDIO OFF)
set(SFML_BUILD_NETWORK OFF)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE FONTES CONFIGURE_DEPENDS src/*.cpp)
add_executable(jogo main.cpp ${FONTES})

target_include_directories(jogo PRIVATE Classes)

target_link_libraries(jogo PRIVATE sfml-graphics sfml-window sfml-system)

set_target_properties(jogo PROPERTIES
    CXX_STANDARD 98
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF)

if(MINGW)
    target_link_options(jogo PRIVATE -static)
endif()