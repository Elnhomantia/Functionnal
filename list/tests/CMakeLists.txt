set(TEST_SOURCES 
    list_trivial.cpp
    list_immutability.cpp
    list_shared.cpp
    list_variadic.cpp
)

set(tests_executables)

get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY) 
get_filename_component(PROJECT_FOLDER ${PARENT_DIR} NAME)

foreach(test_file IN LISTS TEST_SOURCES)
    get_filename_component(file_name ${test_file} NAME_WE)

    add_executable(${file_name} ${test_file})
    target_link_libraries(${file_name} PRIVATE option)
    target_include_directories(${file_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)

    add_test(NAME ${file_name} COMMAND ${file_name})
    list(APPEND tests_executables ${file_name})
endforeach()