#include <stdio.h>

#define STUDENTS 4
#define TESTS 3

/* Job 1 & 6: Print the gradebook table */
void print_table(const int grid[][TESTS], int rows) {
    printf("Student  Test1  Test2  Test3\n");
    for (int r = 0; r < rows; r++) {
        printf("%-8d", r + 1);
        for (int c = 0; c < TESTS; c++) {
            printf("%7d", grid[r][c]);
        }
        printf("\n");
    }
}

/* Job 2: Calculate student average using pointer arithmetic only (no [ ]) */
double calculate_student_average(const int *row, int test_count) {
    int sum = 0;
    for (int i = 0; i < test_count; i++) {
        sum += *(row + i);
    }
    return (double)sum / test_count;
}

/* Job 3: Calculate the class average for each test */
void print_test_averages(const int grid[][TESTS], int rows) {
    printf("Test averages:\n");
    for (int c = 0; c < TESTS; c++) {
        int sum = 0;
        for (int r = 0; r < rows; r++) {
            sum += grid[r][c];
        }
        double avg = (double)sum / rows;
        printf("Test %d: %.2f\n", c + 1, avg);
    }
}

/* Job 4: Find highest score and return all 3 values via pointers */
void find_highest_score(const int grid[][TESTS], int rows, int *highest, int *student_num, int *test_num) {
    *highest = grid[0][0];
    *student_num = 1;
    *test_num = 1;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < TESTS; c++) {
            if (grid[r][c] > *highest) {
                *highest = grid[r][c];
                *student_num = r + 1;
                *test_num = c + 1;
            }
        }
    }
}

/* Job 5: Add bonus points to Test 3 (capped at 100) directly in the original array */
void add_test3_bonus(int grid[][TESTS], int rows, int bonus) {
    for (int r = 0; r < rows; r++) {
        grid[r][2] += bonus;
        if (grid[r][2] > 100) {
            grid[r][2] = 100;
        }
    }
}

/* Job 2 runner: Display all student averages */
void display_all_student_averages(const int grid[][TESTS], int rows) {
    printf("Student averages:\n");
    for (int r = 0; r < rows; r++) {
        /* grid[r] passes a pointer to the start of row r */
        double avg = calculate_student_average(grid[r], TESTS);
        printf("Student %d: %.2f\n", r + 1, avg);
    }
}

int main(void) {
    int scores[STUDENTS][TESTS] = {
        {78, 85, 92},
        {64, 70, 58},
        {90, 88, 97},
        {55, 61, 73}
    };

    /* 1. Print initial table */
    print_table(scores, STUDENTS);

    /* 2. Print student averages */
    display_all_student_averages(scores, STUDENTS);

    /* 3. Print test averages */
    print_test_averages(scores, STUDENTS);

    /* 4. Find and print highest score returned through pointers */
    int best_score;
    int best_student;
    int best_test;
    find_highest_score(scores, STUDENTS, &best_score, &best_student, &best_test);
    printf("Highest score: %d (Student %d, Test %d)\n", best_score, best_student, best_test);

    /* 5. Add 5 bonus points to Test 3 */
    add_test3_bonus(scores, STUDENTS, 5);

    /* 6. Print table after bonus */
    printf("After adding 5 bonus points to Test 3:\n");
    print_table(scores, STUDENTS);

    return 0;
}