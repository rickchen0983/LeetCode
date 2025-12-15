#include <stdio.h>
#include <stdlib.h>
#include "ListLib/List.h"
#include "Solution/AddTwoLists/AddTwoLists.h"
#include "Solution/MergeKLists/MergeKLists.h"
#include "Solution/MergeSortedArray/MergeSortedArray.h"

#define PROJECT_ADDTWOLISTS 2
#define PROJECT_MERGEKLISTS 23
#define PROJECT_MERGESORTEDARRAY 88

#define QUESTION_NUMBER PROJECT_MERGESORTEDARRAY

int main(void)
{
#if QUESTION_NUMBER == PROJECT_ADDTWOLISTS
    AddTwoList_Main();
#endif
#if QUESTION_NUMBER == PROJECT_MERGEKLISTS
    MergeKLists_Main();
#endif
#if QUESTION_NUMBER == PROJECT_MERGESORTEDARRAY
    MergeSortedArray_Main();
#endif
    return 0;
}