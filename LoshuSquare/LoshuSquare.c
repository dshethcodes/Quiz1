#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

bool is_magic(int array[3][3]) {
    int sum = 15; 
    for (int i = 0; i < 3; i++) {
        int row_sum = 0;
        int col_sum = 0;
        for (int j = 0; j < 3; j++) {
            row_sum += array[i][j];
            col_sum += array[j][i];
        }
        if (row_sum != sum || col_sum != sum) {
            return false;
        }
    }
    if (array[0][0] + array[1][1] + array[2][2] != sum || array[0][2] + array[1][1] + array[2][0] != sum) {
        return false;
    }
    return true;
}

void print_array(int array[3][3]) {
    printf("[%d %d %d]\n[%d %d %d]\n[%d %d %d]\n",
        array[0][0], array[0][1], array[0][2],
        array[1][0], array[1][1], array[1][2],
        array[2][0], array[2][1], array[2][2]);
}

int main() {
    srand(time(NULL)); 

    int c = 0;
    while (1) {
        c++;
        int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 8; i > 0; i--) {
            int j = rand() % (i + 1);
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        int array[3][3];
        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                array[i][j] = nums[k];
                k++;
            }
        }
        if (is_magic(array)) {
            printf("Total number of squares generated and tested before success: %d\n", c);
            print_array(array);
            break;
        }
    }

    return 0;
}