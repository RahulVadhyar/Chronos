set(EDITOR_DIR Source/Editor)
file(GLOB EDITOR *.cpp)
target_include_directories(ChronosEditor PUBLIC .)
target_sources(ChronosEditor PRIVATE ${EDITOR})
