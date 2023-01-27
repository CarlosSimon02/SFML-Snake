
cmake_minimum_required(VERSION 3.19)

project(SFML-Snake VERSION 1.0)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
	SFML
	GIT_REPOSITORY https://github.com/SFML/SFML.git
	GIT_TAG 2.5.1
)
set(SFML_BUILD_EXAMPLES OFF)
set(SFML_BUILD_DOC OFF)
option(SFML_BUILD_AUDIO "Build audio" OFF)
option(SFML_BUILD_NETWORK "Build network" OFF)
FetchContent_MakeAvailable(SFML)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(SOURCE
    "src/main.cpp" 
    "src/Game.cpp" 
    "src/Snake.cpp" 
    "src/Food.cpp" 
)

add_executable(
	${PROJECT_NAME} ${SOURCE}
)

target_link_libraries(
	${PROJECT_NAME}
	sfml-graphics
)
