#include <stdio.h> 
void printMatrix(float A[10][10], int n) { 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n + 1; j++) { 
            printf("%.2f\t", A[i][j]); 
        } 
        printf("\n"); 
    } 
    printf("\n"); 
} 
 
void gaussJordanElimination(float A[10][10], int n) { 
    for (int i = 0; i < n; i++) { 
         
        float divisor = A[i][i]; 
        for (int j = 0; j <= n; j++) { 
            A[i][j] /= divisor; 
        } 
 
        for (int k = 0; k < n; k++) { 
            if (k != i) { 
                float factor = A[k][i]; 
                for (int j = 0; j <= n; j++) { 
                    A[k][j] -= factor * A[i][j]; 
                } 
            } 
        } 
 
        printf("After iteration %d:\n", i + 1); 
        printMatrix(A, n); 
    } 
} 
int main() { 
    int n; 
    printf("Enter the number of equations: "); 
    scanf("%d", &n); 
    float A[10][10]; 
    printf("Enter the augmented matrix coefficients:\n"); 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j <= n; j++) { 
            scanf("%f", &A[i][j]); 
        } 
    } 
    printf("Initial Augmented Matrix:\n"); 
    printMatrix(A, n); 
 
    gaussJordanElimination(A, n); 
 
    printf("Solution:\n"); 
    for (int i = 0; i < n; i++) { 
        printf("X%d = %.2f\n", i + 1, A[i][n]); 
    } 
 
    return 0; 
} 