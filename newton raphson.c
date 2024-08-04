#include <stdio.h> 
#include <math.h> 
 
double equation(double x) { 
    return cos(x) - 1;  
} 
 
double derivative(double x) { 
    return -sin(x);  
} 
 
double newtonRaphson(double x0, double epsilon, int maxIterations) { 
    double x = x0; 
    int iteration = 0; 
 
    while (iteration < maxIterations) { 
        double fx = equation(x); 
        double fpx = derivative(x); 
 
        if (fabs(fpx) < 1e-10) { 
            printf("Derivative is too small. Newton-Raphson method can't continue.\n"); 
            return -1.0;  
        } 
 
        double deltaX = fx / fpx; 
        x -= deltaX; 
        iteration++; 
 
        printf("Iteration %d: x = %.6f, f(x) = %.6f, f'(x) = %.6f, delta_x = %.6f\n", iteration, x, fx, fpx, deltaX); 
 
        if (fabs(deltaX) < epsilon) { 
            break; 
        } 
    } 
 
    return x; 
} 
 
int main() { 
    double x0, epsilon, root; 
    int maxIterations; 
printf("Enter the initial guess (x0): "); 
scanf("%lf", &x0); 
printf("Enter the desired accuracy (epsilon): "); 
scanf("%lf", &epsilon); 
printf("Enter the maximum number of iterations: "); 
scanf("%d", &maxIterations); 
root = newtonRaphson(x0, epsilon, maxIterations); 
if (root != -1.0) { 
printf("The root is approximately: %.6f\n", root); 
} 
return 0; 
}