# get the name of the current module
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME module)

# set the binary output directory for the lessons
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${module}/Lessons")

# add lessons and practical work directory to the build
add_subdirectory(PracticalWork)
