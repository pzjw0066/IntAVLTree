cmake_minimum_required(VERSION 4.0.0)

project(AVLTree)

add_executable(AVLTreeTest ${CMAKE_SOURCE_DIR}/src/IntAVLTree.c ${CMAKE_SOURCE_DIR}/src/test.c)
add_library(AVLTree ${CMAKE_SOURCE_DIR}/src/IntAVLTree.c)

target_include_directories(AVLTreeTest PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(AVLTree PUBLIC ${CMAKE_SOURCE_DIR}/include)