set(PRACTICE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# set the binary output directory for the practical work
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${module}/Practice")

# add task directory to the build
add_subdirectory(Task-1)
add_subdirectory(Task-2)
add_subdirectory(Task-3)
add_subdirectory(Task-4)
