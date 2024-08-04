#include <stdio.h> 
#include <math.h> 
 
double equation(double x) { 
    return x * x - 4; 
} 
double iterationFunction(double x) { 
    return sqrt(4 + x); 
} 
double iterate(double initialGuess, double epsilon, int maxIterations) { 
    double x = initialGuess; 
    int iteration = 0; 
 
    while (iteration < maxIterations) { 
        double next_x = iterationFunction(x); 
        iteration++; 
 
        printf("Iteration %d: x = %.6f\n", iteration, next_x); 
 
        if (fabs(next_x - x) < epsilon) { 
            x = next_x; 
            break; 
        } 
 
        x = next_x; 
    } 
 
    return x; 
} 
 
int main() { 
    double initialGuess, epsilon, root; 
    int maxIterations; 
    printf("Enter the initial guess: "); 
    scanf("%lf", &initialGuess); 
    printf("Enter the desired accuracy (epsilon): "); 
    scanf("%lf", &epsilon); 
    printf("Enter the maximum number of iterations: "); 
    scanf("%d", &maxIterations); 
 
    root = iterate(initialGuess, epsilon, maxIterations); 
 
printf("The root is approximately: %.6f\n", root); 
return 0; 
}