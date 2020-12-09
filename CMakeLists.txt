cmake_minimum_required(VERSION 2.8)

project (cs8395project)

find_package (ITK REQUIRED)
include (${ITK_USE_FILE})

add_executable (cs8395project cs8395project.cxx)

target_link_libraries (vtksegmentation ${ITK_LIBRARIES})
