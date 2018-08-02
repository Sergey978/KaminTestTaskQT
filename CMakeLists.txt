project(KaminTestQt)
cmake_minimum_required(VERSION 2.8)
set (CMAKE_CXX_STANDARD 11)
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME} ${SRC_LIST})

#set (gtest_disable_pthreads on)
#add_subdirectory (googletest-master)

#target_link_libraries (${PROJECT_NAME} gtest gmock)
