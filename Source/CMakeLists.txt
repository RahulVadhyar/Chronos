add_subdirectory(Common)
add_subdirectory(Engine)
add_subdirectory(Animation)
add_subdirectory(API)

if(CHRONOS_BUILD_EDITOR)
    add_subdirectory(Editor)
endif()
