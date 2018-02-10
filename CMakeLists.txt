# Common stuff

cmake_minimum_required(VERSION 3.0.2)
project(furnituresimulator)

add_definitions(-Wall)

# Paths and stuff

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

file(GLOB SOURCES_KERNEL "kernel/*.cpp")
file(GLOB SOURCES_FSGUI "gui/*.cpp")

set(SOURCES_TARGET_FURNITURESIMULATOR ${SOURCES_KERNEL})
set(SOURCES_TARGET_FSGUI ${SOURCES_FSGUI})

# Required libs

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
find_package(PythonLibs 3 REQUIRED)

find_package(Boost 1.62.0 REQUIRED COMPONENTS filesystem)

link_directories(${GTKMM_LIBRARY_DIRS} ${LIBRARY_OUTPUT_PATH} ${Boost_LIBRARIES})
include_directories(include ${GTKMM_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})

# Sources

add_library(fsgui STATIC ${SOURCES_TARGET_FSGUI})
add_executable(furnituresimulator ${SOURCES_TARGET_FURNITURESIMULATOR})

target_link_libraries(furnituresimulator ${GTKMM_LIBRARIES} ${PYTHON_LIBRARIES} ${Boost_LIBRARIES} fsgui)





