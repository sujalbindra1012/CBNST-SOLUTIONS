#include <stdio.h>
#include <math.h>

void forwardElimination(float A[][10], int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = k + 1; i < n; i++)
        {
            float factor = A[i][k] / A[k][k];
            for (int j = k; j < n + 1; j++)
            {
                A[i][j] -= factor * A[k][j];
            }
        }
    }
}

void backSubstitution(float A[][10], int n, float X[])
{
    for (int i = n - 1; i >= 0; i--)
    {
        X[i] = A[i][n];
        for (int j = i + 1; j < n; j++)
        {
            X[i] -= A[i][j] * X[j];
        }
        X[i] /= A[i][i];
    }
}

int main()
{
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    float A[10][10];
    float X[10];

    printf("Enter the augmented matrix coefficients:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            scanf("%f", &A[i][j]);
        }
    }

    printf("Augmented Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%.2f\t", A[i][j]);
        }
        printf("\n");
    }

    forwardElimination(A, n);

    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%.2f\t", A[i][j]);
        }
        printf("\n");
    }

    backSubstitution(A, n, X);
    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("X%d = %f\n", i + 1, X[i]);
    }
    return 0;
}