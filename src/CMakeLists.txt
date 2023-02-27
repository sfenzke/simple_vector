add_executable(vector_test main.c)

# configure the vector lib
add_library(vector_lib vector.c)
target_include_directories(vector_lib PRIVATE ${PROJECT_SOURCE_DIR}/include/vector)
target_include_directories(vector_lib PUBLIC ${PROJECT_SOURCE_DIR}/include/vector/interface)
target_link_libraries(vector_test vector_lib)
