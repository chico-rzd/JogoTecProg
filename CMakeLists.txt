cmake_minimum_required(VERSION 3.16)
project(JogoTecProg CXX)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# SFML estatico sem DLLs do SFML
set(BUILD_SHARED_LIBS OFF)      
set(SFML_BUILD_AUDIO OFF)
set(SFML_BUILD_NETWORK OFF)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.1)
FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE FONTES CONFIGURE_DEPENDS src/*.cpp)
add_executable(jogo src/main.cpp ${FONTES}
    Classes/ListaEntidades.h
    Classes/Lista.h)

target_include_directories(jogo PRIVATE Classes)

target_link_libraries(jogo PRIVATE sfml-graphics sfml-window sfml-system)

set_target_properties(jogo PROPERTIES
    CXX_STANDARD 98
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    # Visual Studio: executa a partir da pasta do executavel
    VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:jogo>")

# Copia a pasta assets (imagens) para junto do executavel apos cada build,
# para que caminhos como "assets/jogador1.png" funcionem.
if(EXISTS "${CMAKE_SOURCE_DIR}/assets")
    add_custom_command(TARGET jogo POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                "${CMAKE_SOURCE_DIR}/assets"
                "$<TARGET_FILE_DIR:jogo>/assets")
else()
    message(WARNING "Pasta assets nao encontrada em ${CMAKE_SOURCE_DIR}/assets")
endif()

if(MINGW)
    target_link_options(jogo PRIVATE -static)
endif()