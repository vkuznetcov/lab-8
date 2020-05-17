cmake_minimum_required(VERSION 3.5)

add_executable(lab-8-data_structures "main.cpp" "OrderedVector.h" "AVLTree.h" "UnorderedSet.h" "Menu.h" "Service.h")

target_link_libraries(lab-8-data_structures utils_static)