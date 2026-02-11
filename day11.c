/*Problem: Write a program to perform addition of two matrices having the same dimensions. 
The sum of two matrices is obtained by adding corresponding elements of the matrices.*/
#include <stdio.h>

int main() {
    int r, c;

    scanf("%d", &r);
    scanf("%d", &c);

    int arr1[r][c];
    int arr2[r][c];
    int arr[r][c];

    // Input first matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    // Input second matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    // Matrix addition
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            arr[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    // Print result
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
