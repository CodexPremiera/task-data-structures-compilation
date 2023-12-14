cmake_minimum_required(VERSION 3.24)
project(The_Finals_Review)

set(CMAKE_CXX_STANDARD 17)

add_executable(The_Finals_Review main.cpp source/structures/list/array_list.h source/structures/queue/queue.h source/structures/list/singly_list.h source/structures/node/node.h source/structures/stacks/stack.h source/structures/deque/deque.h source/structures/list/doubly_list.h source/program/program.cpp source/program/program.h source/structures/list/int_list.h source/tree/binary_tree.h source/tree/binary_search_tree.h source/tree/heap.h)
