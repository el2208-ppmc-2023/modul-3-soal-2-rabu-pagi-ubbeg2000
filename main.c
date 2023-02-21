/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void print_matrix(int *matrix)
{
    printf("Matrix:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", *(matrix + i * 4 + j));
        }
        printf("\n");
    }
}

void rotate_matrix(int *matrix, int degree)
{
    int temp[4][4];
    for (int i = 0; i < degree / 90; i++)
    {
        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                temp[col][3 - row] = *(matrix + row * 4 + col);
            }
        }
        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 4; col++)
            {
                *(matrix + row * 4 + col) = temp[row][col];
            }
        }
    }
}

int main()
{
    int matrix[4][4];
    printf("Enter 16 integers for the matrix:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    bool prime = true, even = true, odd = true, mult4 = true;
    for (int i = 0; i < 4; i++)
    {
        if (!is_prime(matrix[0][i]))
        {
            prime = false;
        }
        if (matrix[1][i] % 2 != 0)
        {
            even = false;
        }
        if (matrix[2][i] % 2 == 0)
        {
            odd = false;
        }
        if (matrix[3][i] % 4 != 0)
        {
            mult4 = false;
        }
    }

    if (prime && even && odd && mult4)
    {
        print_matrix(&matrix[0][0]);
        int degree;
        printf("Enter 90, 180, or 270 to rotate the matrix: ");
        scanf("%d", &degree);
        rotate_matrix(&matrix[0][0], degree);
        print_matrix(&matrix[0][0]);
    }
    else
    {
        printf("Matrix You Enter is not an Improper Matrix.\n");
    }

    return 0;
}
