// Q- Write a C program to perform addition and multiplication on matrix using 2-D array.
#include <stdio.h>
// Function to calculate sum of matrices
void sumMatrix(int r, int c, int Mat1[r][c], int Mat2[r][c])
{
    int sum[r][c];
    // Double for loop due to 2-D array
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            sum[i][j] = Mat1[i][j] + Mat2[i][j];
        }
    }
    printf("\nThe sum of the given 2 matrices is: \n");

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
}
// Function to determine multiplication of matrices
void mulMatrix(int r1, int r2, int c1, int c2, int mat1[r1][c1], int mat2[r2][c2])
{
    int product[r1][c2]; // Ex- if Matrix1 is of 2x3 and Matrix2 is of 3x4. The product matrix is of 2x4.
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            product[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                product[i][j] += mat1[i][k] * mat2[k][j]; // k iterates over the column of 1st matrix and row of second matrix as c1 = r2.
            }
        }
    }
    printf("\nThe multiplication of given 2 matrices is: \n");

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d\t", product[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int rows1, columns1, rows2, columns2;
    printf("Enter the number of rows for 1st Matrix: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns for 1st Matrix: ");
    scanf("%d", &columns1);
    printf("\nEnter the number of rows for 2nd Matrix: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns for 2nd Matrix: ");
    scanf("%d", &columns2);
    int matrix1[rows1][columns1], matrix2[rows2][columns2];

    printf("\nEnter the elements of 1st Matrix: \n");
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns1; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("\nEnter the elements of 1st Matrix: \n");
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }
    // Condition of addition of 2 matrices
    if (rows1 == rows2 && columns1 == columns2)
    {
        sumMatrix(rows1, columns1, matrix1, matrix2);
    }
    else
    {
        printf("\nMatrix addition not possible. Dimensions of both matrices must match.\n");
    }
    // Condition of multiplication of 2 matrices
    if (columns1 == rows2)
    {
        mulMatrix(rows1, rows2, columns1, columns2, matrix1, matrix2);
    }
    else
    {
        printf("\nMatrix multiplication not possible. Number of columns of matrix 1 must equal the number of rows of matrix 2.\n");
    }

    return 0;
}