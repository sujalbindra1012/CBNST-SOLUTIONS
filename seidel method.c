#include <stdio.h>
#include <math.h>

#define N 10

void gaussSeidel(float A[N][N], float B[N], float X[N], int n, float tol, int maxIter)
{
    int i, j, iter;
    float sum;

    for (iter = 0; iter < maxIter; iter++)
    {
        for (i = 0; i < n; i++)
        {
            sum = 0.0;
            for (j = 0; j < n; j++)
            {
                if (j != i)
                {
                    sum += A[i][j] * X[j];
                }
            }
            X[i] = (B[i] - sum) / A[i][i];
        }

        // Check for convergence
        int converged = 1;
        for (i = 0; i < n; i++)
        {
            if (fabs(X[i] - X[i]) > tol)
            {
                converged = 0;
                break;
            }
        }

        if (converged)
        {
            printf("Converged after %d iterations:\n", iter + 1);
            for (i = 0; i < n; i++)
            {
                printf("X%d = %f\n", i + 1, X[i]);
            }
            return;
        }
    }

    printf("Gauss-Seidel method did not converge after %d iterations.\n", maxIter);
}

int main()
{
    int n;
    printf("Enter the number of equations: ");
    scanf("%d", &n);

    float A[N][N], B[N], X[N], tol;
    int maxIter;

    printf("Enter the augmented matrix coefficients:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &A[i][j]);
        }
        scanf("%f", &B[i]);
    }

    printf("Enter the initial approximation:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &X[i]);
    }
    printf("Enter the tolerance: ");
    scanf("%f", &tol);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIter);
    gaussSeidel(A, B, X, n, tol, maxIter);
    return 0;
}