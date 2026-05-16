// CMP_SC 4050
// Fall 2024
// A4 - "Bad Scantron"
//
#include <stdio.h>
#include "grade.h"

int main(void)
{
    int key[40] =
    {
        5,2,3,2,2,1,4,4,1,5,2,3,1,2,1,3,2,3,2,1,5,4,2,4,3,2,3,3,4,5,1,5,3,4,3,4,2,1,1,4
    };
    int keyResponseCount = 40;

    int exams[][40] = 
    {
        {4,2,3,3,2,1,4,2,5,2,4,3,3,2,2,3,1,2,1,1,2,3,1,4,4,3,1,4,5,1,5,3,2,5,2,2,4},
        {4,2,4,2,2,2,4,5,2,3,1,5,3,2,4,3,1,1,3,3,2,1,4,1,3,3,4,5,1,2,2,5,3,4,2,1,4,4},
        {2,3,3,2,1,4,1,5,5,3,3,1,3,5,2,1,1,3,1,1,3,3,1,3,4,3,1,4,5,2,5,2,1,2,4,4,2,4},
        {2,2,3,2,2,1,4,4,1,2,2,3,1,2,1,2,2,3,5,1,3,4,2,4,3,2,3,3,1,5,2,5,3,4,3,4,3,1,3,5},
        {1,1,3,3,2,1,5,5,5,5,4,5,1,3,3,2,3,3,1,1,3,5,2,1,3,4,3,3,4,5,2,5,2,3,4,2,2,2,1,3},
        {3,2,5,2,1,4,4,1,5,2,2,2,5,4,3,3,1,5,3,2,5,3,3,3,5,1,5,5,2,5,3,2,1,1,1},
    };
    int examResponseCounts[] = 
    {
        37,38,38,40,40,35
    };
    int examCount = sizeof(examResponseCounts)/sizeof(examResponseCounts[0]);

    printf("The key scored %d out %d against itself.\n",Grade(key,keyResponseCount,key,keyResponseCount),keyResponseCount);
    for (int i=0;i<examCount;i++)
    {
        printf("Exam #%d scored %d out of %d.\n",i,Grade(key,keyResponseCount,exams[i],examResponseCounts[i]),keyResponseCount);
    }
}
