cmake_minimum_required(VERSION 3.28)
project(data_c C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "-fexec-charset=UTF-8")
add_executable(data_c main.c
        Sosu/sosu.c
        DataProject.h
        Recursive/recursive.c
        Recursive/recursive.h
        List/LinkedList.c
        List/LinkedList.h
        List/Member.c
        List/Member.h
        Stack/stack.c
        Stack/stack.h
        Queue/Queue.c
        Queue/Queue.h
        Postfix/Postfix.c
        Postfix/Postfix.h
        Calculator/Calculator.c
        Calculator/Calculator.h
        Stack/DoubleStack.h
        Stack/DoubleStack.c
        CircleQueue/CircleQueue.c
        CircleQueue/CircleQueue.h
        BinaryTree/BinaryTree.c
        BinaryTree/BinaryTree.h
        Heap/Heap.c
        Heap/Heap.h
        Graph/Graph.c
        Graph/Graph.h
        Hash/ChainHash.c
        Hash/ChainHash.h
        Hash/OpenAddress.c
        Hash/OpenAddress.h
        Sort/BubbleSort.c
        Sort/BubbleSort.h
        Sort/Sort.h
        Sort/SelectionSort.c
        Sort/SelectionSort.h
)
