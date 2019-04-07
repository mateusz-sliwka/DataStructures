cmake_minimum_required(VERSION 3.13)
project(SDiZO_Sliwka)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDiZO_Sliwka main.cpp Timer.cpp Timer.h Array.cpp Array.h ManualTests.cpp ManualTests.h AutomaticTests.cpp AutomaticTests.h ListElement.cpp ListElement.h List.cpp List.h Heap.cpp Heap.h TreeElement.cpp TreeElement.h Tree.cpp Tree.h)