cmake_minimum_required(VERSION 4.1)
project(LeetCodeVsCode C)

set(CMAKE_C_STANDARD 11)

include_directories(ListLib)
include_directories(Solution/AddTwoLists)
include_directories(Solution/IntegerToRoman)
include_directories(Solution/MergeKLists)
include_directories(Solution/MergeSortedArray)
include_directories(Solution/RemoveNthFromEnd)

add_executable(LeetCodeVsCode
        ListLib/List.c
        ListLib/List.h
        Solution/AddTwoLists/AddTwoLists.c
        Solution/AddTwoLists/AddTwoLists.h
        Solution/IntegerToRoman/IntegerToRoman.c
        Solution/IntegerToRoman/IntegerToRoman.h
        Solution/MergeKLists/MergeKLists.c
        Solution/MergeKLists/MergeKLists.h
        Solution/MergeSortedArray/MergeSortedArray.c
        Solution/MergeSortedArray/MergeSortedArray.h
        Solution/RemoveNthFromEnd/RemoveNthFromEnd.c
        Solution/RemoveNthFromEnd/RemoveNthFromEnd.h
        Main.c)
