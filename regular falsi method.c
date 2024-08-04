#include <stdio.h>
#include <math.h>
double equation(double x)
{
    return x * x - 4;
}
double regulaFalsi(double a, double b, double epsilon, int maxIterations)
{
    double c, fc;
    int iteration = 0;

    if (equation(a) * equation(b) >= 0)
    {
        printf("Invalid initial values. Root not bracketed.\n");
        return -1.0;
    }

    while (iteration < maxIterations)
    {
        c = (a * equation(b) - b * equation(a)) / (equation(b) - equation(a));
        fc = equation(c);
        iteration++;

        printf("Iteration %d: a = %.6f, b = %.6f, c = %.6f, f(c) = %.6f\n", iteration, a, b, c,
               fc);

        if (fc == 0.0 || fabs(b - a) < epsilon)
        {
            break;
        }
        else if (fc * equation(a) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    return c;
}

int main()
{
    double a, b, epsilon, root;
    int maxIterations;

    printf("Enter the initial interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the desired accuracy (epsilon): ");
    scanf("%lf", &epsilon);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);
    root = regulaFalsi(a, b, epsilon, maxIterations);
    if (root != -1.0)
    {
        printf("The root is approximately: %.6f\n", root);
    }
    return 0;
}
