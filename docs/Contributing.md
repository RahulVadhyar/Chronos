# Contributing

[TOC]

## Table of Contents
+ Disclaimer
+ Codebase Structure
+ Developing Chronos
    + How to debug
    + Testing
    + Merging your change
    + Profiling Chronos
+ Writing Documentation
+ [Formatting](#formatting)

This project is still under development. All features, api and function calls are not final and will change. However if you see any bug or unexpected behaviour, or have suggestions you want to make, you can file an issue or open a PR. 
Please be polite. If you do contribute any code, all ownership of the code shall be transferred to me and you will have no rights over the code. 

## Formatting

Before committing your code, it is advisable to format your code. You can do this automatically using clang-format. You will need to run using the ```.clang-format``` file in the root directory.
This can be easily done by installing clang-format and then from the root directory, just run the below command:

~~~ bash
SOURCE_DIR="Source" && find "$SOURCE_DIR" -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.h" -o -name "*.hpp" -o -name "*.tpp" \) | while read -r FILENAME; do clang-format -i "$FILENAME"; done
~~~