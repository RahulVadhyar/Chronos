# SPDX-License-Identifier: BSD-3-Clause
#Taken from KDE Clang format and modified.
find_program(CLANG_FORMAT_EXECUTABLE clang-format)

# formatting target
function(CHRONOS_CLANG_FORMAT)
    if (TARGET clang-format)
        # We can only define one clang-format target
        return()
    endif()

    # add target without specific commands first, we add the real calls file-per-file to avoid command line length issues and enable parallelization
    add_custom_target(clang-format COMMENT "Formatting sources in ${CMAKE_CURRENT_SOURCE_DIR} with ${CLANG_FORMAT_EXECUTABLE}...")

    # run clang-format only if available, else signal the user what is missing
    if(CLANG_FORMAT_EXECUTABLE)
        get_filename_component(_binary_dir ${CMAKE_BINARY_DIR} REALPATH)
        set(_ci_install_dir "${CMAKE_SOURCE_DIR}/_install") # on the KDE-CI, we install dependencies in-source
        foreach(_file ${ARGV})
            # check if the file is inside the build directory => ignore such files
            get_filename_component(_full_file_path ${_file} REALPATH)
            string(FIND ${_full_file_path} ${_binary_dir} _binary_idx)
            string(FIND ${_full_file_path} ${_ci_install_dir} _dependency_idx)
            if(NOT _binary_idx EQUAL 0 AND NOT _dependency_idx EQUAL 0)
                get_filename_component(_file_name ${_file} NAME)
                file(RELATIVE_PATH _rel_file_path ${CMAKE_SOURCE_DIR} ${_full_file_path})
                string(REPLACE "/" "_" unique_target_name "clang-format-${_rel_file_path}")
                string(REPLACE "%" "_" unique_target_name ${unique_target_name}) # some imvalid cmake target names
                string(REPLACE "{" "_" unique_target_name ${unique_target_name})
                string(REPLACE "}" "_" unique_target_name ${unique_target_name})
                add_custom_target(${unique_target_name}
                    DEPENDS ${_full_file_path}
                )
                add_custom_command(TARGET ${unique_target_name}
                    POST_BUILD
                    COMMAND ${CLANG_FORMAT_EXECUTABLE} -style=file -i ${_full_file_path}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                )
                add_dependencies(clang-format ${unique_target_name})
            endif()
        endforeach()
    else()
        add_custom_command(TARGET clang-format
            COMMAND
                ${CMAKE_COMMAND} -E echo "Could not set up the clang-format target as the clang-format executable is missing."
            )
    endif()
endfunction()