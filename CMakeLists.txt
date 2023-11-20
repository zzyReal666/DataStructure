cmake_minimum_required(VERSION 3.26)
project(DataStructure C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructure main.c
        SqList/SqList.h
        SqList/SqList.c
        SqList/SqListExercises.c
        SqList/SqListExercises.h
        LinkedList/LinkedList.h
        LinkedList/LinkedList.c)
