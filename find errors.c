#include <stdio.h>
#include <math.h>
double polynomial(double x)
{
    return x * x - 2 * x + 1;
}
int main()
{
    double x_actual;
    double x_calculated;
    double actual_result;
    double calculated_result;

    double abs_error, rel_error, per_error;
    printf("enter the actual value :");
    scanf("%lf", &x_actual);

    printf("enter the  calculated input value :");
    scanf("%lf", &x_calculated);

    actual_result = polynomial(x_actual);
    calculated_result = polynomial(x_calculated);
    
    abs_error = fabs(actual_result - calculated_result);
    rel_error = abs_error / fabs(actual_result);
    per_error = rel_error * 100;
    
    printf("Calculated Result: %.4f\n", calculated_result);
    printf("Absolute Error: %.4f\n", abs_error);
    printf("Relative Error: %.4f\n", rel_error);
    printf("Percentage Error: %.4f%%\n", per_error);
    
    return 0;
}