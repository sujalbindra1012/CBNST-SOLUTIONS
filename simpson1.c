#include <stdio.h>
float f(float x)
{
    return 1 / (1 + (x * x));
}
int main()
{
    int n;
    float x0, y0, sum = 0, i, h;
    int pos = 1;
    printf("enter values of x0 and y0:");
    scanf("%f %f", &x0, &y0);
    printf("enter no of intervals in even:");
    scanf("%d", &n);
    h = (y0 - x0) / n;
    sum = f(x0) + f(y0);
    for (i = x0 + h; i < y0; i = i + h)
    {
        if (pos % 2 == 0)
        {
            sum = sum + 2 * f(i);
        }
        else
        {
            sum = sum + 4 * f(i);
        }
        pos++;
    }
    sum = (h * sum) / 3;
    printf("value of integral is %f", sum);
}