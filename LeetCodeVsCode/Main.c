#include <stdio.h>
#include <stdlib.h>
#include "ListLib/List.h"
#include "Solution/AddTwoLists/AddTwoLists.h"
#include "Solution/MergeKLists/MergeKLists.h"
#include "Solution/MergeSortedArray/MergeSortedArray.h"
#include "Solution/IntegerToRoman/IntegerToRoman.h"
#include "Solution/RemoveNthFromEnd/RemoveNthFromEnd.h"
#include "Solution/DeleteDuplicates/DeleteDuplicates.h"

#define PROJECT_ADDTWOLISTS 2
#define PROJECT_MERGEKLISTS 23
#define PROJECT_MERGESORTEDARRAY 88
#define PROJECT_INTEGERTOROMAN 12
#define PROJECT_REMOVENTHFROMEND 19
#define PROJECT_DELETE_DUPLICATES 83

#define QUESTION_NUMBER PROJECT_DELETE_DUPLICATES

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
#if QUESTION_NUMBER == PROJECT_INTEGERTOROMAN
    IntegerToRoman_Main();
#endif
#if QUESTION_NUMBER == PROJECT_REMOVENTHFROMEND
    RemoveNthFromEnd_Main();
#endif
#if QUESTION_NUMBER == PROJECT_DELETE_DUPLICATES
    DeleteDuplicates_Main();
#endif
    return 0;
}