//Q- Write a C program to display the inverse of a 3*3 matrix-using array.

#include <stdio.h>

// Function to calculate determinant of a 3x3 matrix
float determinant(float matrix[3][3]) {
    return matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[1][2]*matrix[2][1]) 
           - matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[1][2]*matrix[2][0])
           + matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[1][1]*matrix[2][0]);
}

// Function to calculate the cofactor matrix
void cofactor(float matrix[3][3], float cofactors[3][3]) {
    int i, j, row, col;
    float temp[3][3];
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            // Find the minor matrix by excluding the ith row and jth column
            row = 0;
            for (int x = 0; x < 3; x++) {
                if (x == i) continue;
                col = 0;
                for (int y = 0; y < 3; y++) {
                    if (y == j) continue;
                    temp[row][col] = matrix[x][y];
                    col++;
                }
                row++;
            }
            
            // Calculate the cofactor of the element
            cofactors[i][j] = (i + j) % 2 == 0 ? determinant(temp) : -determinant(temp);
        }
    }
}

// Function to find the adjoint of the matrix
void adjoint(float matrix[3][3], float adj[3][3]) {
    float cofactors[3][3];
    cofactor(matrix, cofactors);
    
    // Transpose the cofactor matrix to get the adjoint
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            adj[i][j] = cofactors[j][i];
        }
    }
}

// Function to find the inverse of the matrix
int inverse(float matrix[3][3], float inverseMatrix[3][3]) {
    float det = determinant(matrix);
    if (det == 0) {
        printf("Matrix is singular, no inverse exists.\n");
        return 0;  // Matrix is singular, no inverse exists
    }
    
    float adj[3][3];
    adjoint(matrix, adj);
    
    // Divide each element of the adjoint matrix by the determinant to get the inverse
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inverseMatrix[i][j] = adj[i][j] / det;
        }
    }
    return 1;  // Inverse exists and is computed
}

// Function to print the matrix
void printMatrix(float matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    float matrix[3][3], invMatrix[3][3];
    
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }
    
    printf("\nOriginal Matrix:\n");
    printMatrix(matrix);
    
    if (inverse(matrix, invMatrix)) {
        printf("\nInverse of the matrix:\n");
        printMatrix(invMatrix);
    }
    
    return 0;
}
