cmake_minimum_required(VERSION 3.4)
project(test_repo CXX)

#set(CMAKE_C_COMPILER "/usr/bin/cc")
#set(CMAKE_CXX_COMPILER "/usr/bin/g++")


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#make a list of all header files
file(GLOB header_files ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h $CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

#make a list of all the source files 
file(GLOB src_files ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)


#add the library
add_library(test_lib ${header_files} ${src_files})

target_include_directories(test_lib PUBLIC 
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> 	
$<INSTALL_INTERFACE:${_include}>)

add_executable(sample sample.cpp)

target_link_libraries(sample test_lib)

INSTALL(TARGETS sample  DESTINATION bin)