#include <stdio.h>
#include <math.h>
double equation(double x)
{
    return x * x - 4;
}

double secant(double x0, double x1, double epsilon, int maxIterations)
{
    double x = x1;
    double x_prev = x0;
    int iteration = 0;

    while (iteration < maxIterations)
    {
        double fx = equation(x);
        double fx_prev = equation(x_prev);

        if (fabs(fx - fx_prev) < epsilon)
        {
            printf("Convergence too slow. Secant method can't continue.\n");
            return -1.0;
        }

        double delta_x = -fx * (x - x_prev) / (fx - fx_prev);
        x_prev = x;
        x += delta_x;
        iteration++;

        printf("Iteration %d: x = %.6f, f(x) = %.6f, delta_x = %.6f\n", iteration, x, fx, delta_x);

        if (fabs(delta_x) < epsilon)
        {
            break;
        }
    }
    return x;
}
int main()
{
    double x0, x1, epsilon, root;
    int maxIterations;
    printf("Enter the initial guesses (x0 and x1): ");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter the desired accuracy (epsilon): ");
    scanf("%lf", &epsilon);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);
    root = secant(x0, x1, epsilon, maxIterations);
    if (root != -1.0)
    {
        printf("The root is approximately: %.6f\n", root);
    }
    return 0;
}