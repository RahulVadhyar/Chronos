if(CHRONOS_ENABLE_PROFILING)
    target_compile_definitions(Chronos PUBLIC CHRONOS_PROFILING)
    if(CHRONOS_BUILD_EDITOR)
        target_compile_definitions(ChronosEditor PUBLIC CHRONOS_PROFILING)
    endif()
endif()

file(GLOB ENGINE *.cpp)
target_sources(Chronos PRIVATE ${ENGINE})
target_include_directories(Chronos PUBLIC .)

if(CHRONOS_BUILD_EDITOR)
    target_sources(ChronosEditor PRIVATE ${ENGINE})
    target_include_directories(ChronosEditor PUBLIC .)
endif()

add_subdirectory(Objects)

