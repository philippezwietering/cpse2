cmake_minimum_required(VERSION 2.6)

project(project)
set(EXE "main")

enable_testing()

set(warnings
    "-Wall"
    "-Wextra"
    "-Wall"
    "-Wextra"
    "-Wpedantic"
    "-Wcast-align"
    "-Wmissing-declarations"
    "-Wredundant-decls"
    "-Wuninitialized"
    "-Wconversion"
    "-Wno-unused-parameter")

set(cxxflags
    "-std=c++14"
    ${warnings})

string(REGEX REPLACE ";" " " cxxflags "${cxxflags}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${cxxflags}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/project)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(sources
    # Main source.
    project/main.cpp
    project/circle.hpp
    project/circle.cpp
    project/rectangle.hpp
    project/rectangle.cpp
    project/drawable.hpp
    project/action.hpp
    project/line.hpp
    project/line.cpp
    project/picture.cpp
    project/picture.hpp
    project/exception.hpp
    project/troll.png
    project/color.hpp)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(Boost REQUIRED COMPONENTS system filesystem)
find_package(SFML 2 REQUIRED system window graphics network audio)

add_executable(${EXE} ${sources})
target_link_libraries(${EXE} ${Boost_LIBRARIES} dl ${SFML_LIBRARIES})
