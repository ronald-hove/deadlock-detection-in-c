cmake_minimum_required(VERSION 3.12)
project(Prac4Deadlock C)

set(CMAKE_C_STANDARD 99)

add_executable(Prac4Deadlock linkedlist.c linkedlist.h helper.c helper.h main.c graph.c graph.h main.h)