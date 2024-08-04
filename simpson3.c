#include <stdio.h>

float f(float x)
{
    return 1 / (1 + x * x);
}

int main()
{
    float x0, y0, sum = 0, h, i;
    printf("Enter the value of x0 and y0:");
    scanf("%f %f", &x0, &y0);
    int n, position = 1;
    printf("Enter the number of intervals :");
    scanf("%d", &n);
    h = (y0 - x0) / n;
    sum = f(x0) + f(y0);
    for (i = x0 + h; i < y0; i = i + h)
    {
        if (position % 3 == 0)
        {
            sum = sum + 2 * f(i);
        }
        else
        {
            sum = sum + 3 * f(i);
        }
        position++;
    }
    sum = ((h * 3) / 8) * sum;
    printf("value of integral is :%f", sum);
    return 0;
}