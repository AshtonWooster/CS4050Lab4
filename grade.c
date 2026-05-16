// CMP_SC 4050
// Fall 2024
// A4 - "Bad Scantron"

#include "grade.h"
#include <stdio.h>
#include <stdlib.h>

#define MEMO_SIZE 50

/*
    This function checks all the provided answers against the key

    Inputs:
        int key[]: the key to check against
        int ans[]: the answers to check
        int key_len: the length of the arrays
    Outputs:
        int: the total number of correct answers
*/
int check_matches(int key[], int ans[], int key_len) {
    int count = 0;
    for (int i = 0; i < key_len; i++) {
        if (key[i] == ans[i]) {
            count++;
        }
    }
    return count;
}

/*
    This function solves the grade alignment problem

    Inputs:
        int key[]: the answer key
        int key_len: the length of the key
        int student_ans[]: the provided student answers
        int student_len: the length of the student answers
    Outputs:
        int: the highest score with shifts for the student_ans
*/
int memo_table[MEMO_SIZE][MEMO_SIZE]; // Formatted as memo_table[remaining key][remaining student ans]
int grade_memo(int key[], int key_len, int student_ans[], int student_len) {
    // Base cases
    if (student_len == 0 || key_len < student_len) {
        return 0;
    }

    // Check memoization if it's already been solved
    if (memo_table[key_len][student_len] != -1) {
        return memo_table[key_len][student_len];
    }

    // See if its better to shift or keep the current answer
    int shift_score = grade_memo(key+1, key_len-1, student_ans, student_len);
    int keep_score = grade_memo(key+1, key_len-1, student_ans+1, student_len-1);
    keep_score += (int)(key[0]==student_ans[0]); // Score current answer

    // Store the result in the memoization table for future calculations
    if (shift_score > keep_score) {
        memo_table[key_len][student_len] = shift_score;
    }
    else {
        memo_table[key_len][student_len] = keep_score;
    }

    return memo_table[key_len][student_len];
}

int Grade(int key[], int keyResponseCount, int exam[], int examResponseCount)
{
    // Initialize memo_table
    for (int i = 0; i<MEMO_SIZE; i++) {
        for (int j = 0; j<MEMO_SIZE; j++) {
            memo_table[i][j] = -1;
        }
    }

    return grade_memo(key, keyResponseCount, exam, examResponseCount);
}
