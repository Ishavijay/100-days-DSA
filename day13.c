/* You are given a rectangular matrix of integers. Starting from the outer boundary, 
traverse the matrix in a clockwise manner and continue moving inward layer by layer 
until all elements are visited.*/
#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    int total = rows * cols;
    *returnSize = total;

    int* result = (int*)malloc(sizeof(int) * total);
    int index = 0;

    while (top <= bottom && left <= right) {

        // Left → Right
        for (int i = left; i <= right; i++) {
            result[index++] = matrix[top][i];
        }
        top++;

        // Top → Bottom
        for (int i = top; i <= bottom; i++) {
            result[index++] = matrix[i][right];
        }
        right--;

        // Right → Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result[index++] = matrix[bottom][i];
            }
            bottom--;
        }

        // Bottom → Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result[index++] = matrix[i][left];
            }
            left++;
        }
    }

    return result;
}

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    // Allocate memory for matrix
    int** matrix = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        matrix[i] = (int*)malloc(c * sizeof(int));
    }

    // Input matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int returnSize;
    int* matrixColSize = (int*)malloc(sizeof(int));
    matrixColSize[0] = c;

    // Call function
    int* result = spiralOrder(matrix, r, matrixColSize, &returnSize);

    // Print spiral order
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    // Free memory
    free(result);
    free(matrixColSize);
    for (int i = 0; i < r; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

