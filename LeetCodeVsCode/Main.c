#include <stdio.h>
#include <stdlib.h>
#include "ListLib/List.h"
#include "Solution/AddTwoLists/AddTwoLists.h"
#include "Solution/MergeKLists/MergeKLists.h"

#define PROJECT_ADDTWOLISTS 2
#define PROJECT_MERGEKLISTS 23

#define QUESTION_NUMBER PROJECT_MERGEKLISTS

int main(void)
{
#if QUESTION_NUMBER == PROJECT_ADDTWOLISTS
    AddTwoList_Main();
#endif
#if QUESTION_NUMBER == PROJECT_MERGEKLISTS
    MergeKLists_Main();
#endif
    return 0;
}