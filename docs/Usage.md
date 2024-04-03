\page Usage

# Usage

* Example 1

This project is designed to be linked to your project with cmake. To link with cmake, install the dependencies as described [here](docs/build.md).
  After that, link it to cmake as follows using the following code as an example.
  ```cmake
  cmake_minimum_required(VERSION 3.13)
  project(YourProject)
  set(CMAKE_CXX_STANDARD 20)
  set(CHRONOS_INCLUDE_DIR path/to/Chronos/include)
  include_directories(BEFORE ${CHRONOS_INCLUDE_DIR})
  
  #add your stuff here
  
  add_subdirectory(path/to/Chronos)
  target_link_libraries(YourProject Chronos)
  ```