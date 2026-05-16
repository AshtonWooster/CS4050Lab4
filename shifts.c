// CS4050
// Ashton Wooster

#include <stdio.h>
#include <stdlib.h>
#define KEY_LEN 7
#define STUDENT_LEN 4

/*
    This function checks all the provided answers against the key

    Inputs:
        int key[]: the key to check against
        int ans[]: the answers to check
    Outputs:
        int: the total number of correct answers
*/
int check_matches(int key[KEY_LEN], int ans[KEY_LEN]) {
    int count = 0;
    for (int i = 0; i < KEY_LEN; i++) {
        if (key[i] == ans[i]) {
            count++;
        }
    }
    return count;
}

/*
    This function will shift an array with the provided answers x indicies

    Inputs: 
        int* shifted_arr: an allocated int array of size key_len to store the results in
        int* ans: the answers to shift
        int x: the number of indicies to shift
        int num_ans: the number of answers provided in ans
*/
void construct_shift(int* shifted_arr, int* ans, int x, int num_ans) {
    // Insert leading sentinels (-1)
    for (int i = 0; i < x; i++) {
        shifted_arr[i] = -1;
    }

    // Copy in ans
    for (int i = x; i < num_ans+x; i++) {
        shifted_arr[i] = *(ans+i-x);
    }

    // Add trailing sentinels (-1)
    for (int i = x+num_ans; i<KEY_LEN; i++) {
        shifted_arr[i] = -1;
    }
}

int main(void) {
    // The key
    int key[KEY_LEN] = {5, 2, 3, 2, 2, 1, 4};

    // The Answers
    int student_answers[STUDENT_LEN] = {3, 2, 2, 1};
    
    // Brute force check all possible shifts
    int shift_count = 0;
    int highest_shift = 0;
    int highest_score = 0;
    int* shifted_arr = calloc(sizeof(int), KEY_LEN);
    do {
        construct_shift(shifted_arr, student_answers, shift_count, STUDENT_LEN);
        
        int score = check_matches(key, shifted_arr);        
        if (score > highest_score) {
            highest_score = score;
            highest_shift = shift_count;
        }

        printf("SHIFT %d:\n Score: %d\n", shift_count, score);

        shift_count++;
    } while(shift_count < KEY_LEN-STUDENT_LEN+1);

    printf("The highest score, %d, occurs at shift %d\n", highest_score, highest_shift);

    construct_shift(shifted_arr, student_answers, highest_shift, STUDENT_LEN);

    printf("KEY:\n");
    for (int i = 0; i < KEY_LEN; i++) {
        printf("%d, ", key[i]);
    }

    printf("\nBEST SHIFT, %d, ANSWERS:\n", highest_shift);
    for (int i = 0; i < KEY_LEN; i++) {
        printf("%d, ", shifted_arr[i]);
    }
    printf("\n");

    free(shifted_arr);
    return 0;
}