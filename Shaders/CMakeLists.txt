file(GLOB SHADERS SPIV/*.spv)

set(SHADER_PATH "\"${CMAKE_CURRENT_BINARY_DIR}/Shaders/\"")

message("Shader path: ${SHADER_PATH}")

message("Moving shaders to build dir")
file(COPY ${SHADERS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Shaders)

target_compile_definitions(Chronos PUBLIC SPIV_SHADER_PATH=${SHADER_PATH})
if(CHRONOS_BUILD_EDITOR)
    target_compile_definitions(ChronosEditor PUBLIC SPIV_SHADER_PATH=${SHADER_PATH})
endif()