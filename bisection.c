#include <stdio.h>
#include <math.h>

double equation(double x)
{
    return x * x * x - x - 1;
}

double bisection(double a, double b, double epsilon)
{
    if (equation(a) * equation(b) >= 0)
    {
        printf("invalid initial values, root not bracketed");
        return -1.0;
    }

    double c, fc;
    int iteration = 0;

    while ((b - a) >= epsilon)
    {
        c = (a + b) / 2.0;
        fc = equation(c);
        iteration++;

        printf("iteration %d:a=%.6f,b=%.6f,c=%.6f,f(c)=%.6f\n", iteration, a, b, c, fc);

        if (fc == 0.0)
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
    printf("Enter the initial interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the desired accuracy (epsilon): ");
    scanf("%lf", &epsilon);
    root = bisection(a, b, epsilon);
    if (root != -1.0)
    {
        printf("The root is approximately: %.6f\n", root);
    }
    return 0;
}
