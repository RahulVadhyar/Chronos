find_program(GLSLC_EXECUTABLE NAMES glslc)

if (GLSLC_EXECUTABLE)
  message(STATUS "Found glslc: ${GLSLC_EXECUTABLE}")
else()
  message(FATAL_ERROR "glslc not found. Please install it to proceed.")
endif()

find_program(XXD_EXECUTABLE NAMES xxd)

if (XXD_EXECUTABLE)
  message(STATUS "Found xxd: ${XXD_EXECUTABLE}")
else()
  message(FATAL_ERROR "xxd not found. Please install it to proceed.")
endif()

set(SHADER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE SHADER_SOURCE_FILES  ${SHADER_SOURCE_DIR}/*.frag ${SHADER_SOURCE_DIR}/*.vert)
set(SHADER_OUTPUT_FILES)
if(NOT SHADER_SOURCE_FILES)
    message(FATAL_ERROR "No shader source files found in ${SHADER_SOURCE_DIR}")
endif()
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/shaders_spv)

foreach(SHADER_SOURCE IN LISTS SHADER_SOURCE_FILES)
    get_filename_component(SHADER_NAME ${SHADER_SOURCE} NAME_WE)
    message("Found shader source: ${SHADER_NAME}")
    set(SPIV_OUTPUT "${CMAKE_BINARY_DIR}/shaders_spv/${SHADER_NAME}.spv")
    set(HEADER_OUTPUT "${CMAKE_BINARY_DIR}/shaders_header/shaders/${SHADER_NAME}.hpp")
    add_custom_command(
    OUTPUT ${HEADER_OUTPUT}
    COMMAND ${GLSLC_EXECUTABLE} ${SHADER_SOURCE} -o ${SPIV_OUTPUT} && cd ${CMAKE_BINARY_DIR}/shaders_spv && (${XXD_EXECUTABLE} -i ${SHADER_NAME}.spv > ${HEADER_OUTPUT})
    DEPENDS ${SHADER_SOURCE}
    COMMENT "Compiling ${SHADER_NAME} to SPIR-V"
    )
    list(APPEND SHADER_OUTPUT_FILES ${HEADER_OUTPUT})
endforeach()
add_custom_target(ChronosShaders ALL DEPENDS ${SHADER_OUTPUT_FILES})
add_dependencies(Chronos ChronosShaders)
add_dependencies(ChronosEditor ChronosShaders)
target_include_directories(Chronos PUBLIC ${CMAKE_BINARY_DIR}/shaders_header)
target_include_directories(ChronosEditor PUBLIC ${CMAKE_BINARY_DIR}/shaders_header)