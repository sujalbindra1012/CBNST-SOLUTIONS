#include <stdio.h>
float f(float x, float y)
{
    return x + y;
}
int main()
{
    float x0, x, y, h;
    printf("enter the value of x0 and y0 ");
    scanf("%f %f", &x0, &y);
    printf("enter value of h:");
    scanf("%f", &h);
    printf("enter the value of x for which you want a y :");
    scanf("%f", &x);
    int n = (int)((x - x0) / h);
    float k1, k2, k3, k4;
    for (int i = 0; i < n; i++)
    {
        k1 = h * f(x0, y);
        k2 = h * f(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * f(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * f(x0 + h, y + k3);

        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 = x0 + h;
    }
    printf("value of y for given x is %f", y);
}
