/*Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it is a square matrix and is equal to its transpose 
(i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).*/
#include <stdio.h>

int main() {
    int size;
    scanf("%d", &size);

    int arr[size][size];

    // Input matrix
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int symmetric = 1;  // Assume symmetric initially

    // Check symmetry
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(arr[i][j] != arr[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if(symmetric == 0)
            break;
    }

    if(symmetric)
        printf("It is a symmetric matrix!!");
    else
        printf("It is not symmetric");

    return 0;
}
