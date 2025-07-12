#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int row, int col) {
    printf("Enter the elements of the matrix (%dx%d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int row, int col) {
    printf("Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int row1, int col1, int row2, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int mat[MAX][MAX], int result[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

int main() {
    int mat1[MAX][MAX], mat2[MAX][MAX], result[MAX][MAX];
    int row1, col1, row2, col2, choice;

    printf("Matrix Calculator\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Matrix Addition:\n");
            printf("Enter rows and columns of the matrices: ");
            scanf("%d %d", &row1, &col1);
            inputMatrix(mat1, row1, col1);
            inputMatrix(mat2, row1, col1);
            addMatrices(mat1, mat2, result, row1, col1);
            printf("Result:\n");
            displayMatrix(result, row1, col1);
            break;

        case 2:
            printf("Matrix Subtraction:\n");
            printf("Enter rows and columns of the matrices: ");
            scanf("%d %d", &row1, &col1);
            inputMatrix(mat1, row1, col1);
            inputMatrix(mat2, row1, col1);
            subtractMatrices(mat1, mat2, result, row1, col1);
            printf("Result:\n");
            displayMatrix(result, row1, col1);
            break;

        case 3:
            printf("Matrix Multiplication:\n");
            printf("Enter rows and columns of the first matrix: ");
            scanf("%d %d", &row1, &col1);
            printf("Enter rows and columns of the second matrix: ");
            scanf("%d %d", &row2, &col2);
            if (col1 != row2) {
                printf("Matrix multiplication not possible!\n");
            } else {
                inputMatrix(mat1, row1, col1);
                inputMatrix(mat2, row2, col2);
                multiplyMatrices(mat1, mat2, result, row1, col1, row2, col2);
                printf("Result:\n");
                displayMatrix(result, row1, col2);
            }
            break;

        case 4:
            printf("Matrix Transpose:\n");
            printf("Enter rows and columns of the matrix: ");
            scanf("%d %d", &row1, &col1);
            inputMatrix(mat1, row1, col1);
            transposeMatrix(mat1, result, row1, col1);
            printf("Transpose:\n");
            displayMatrix(result, col1, row1);
            break;

        case 5:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
