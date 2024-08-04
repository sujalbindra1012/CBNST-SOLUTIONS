#include <stdio.h>

int main()
{
    int n;
    printf("Enter the number of equations:");
    scanf("%d", &n);
    float X[n], Y[n], sx = 0, sy = 0, sx2 = 0, sxy = 0;
    printf("Enter the values of x:");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &X[i]);
    }
    printf("Enter the values of y:");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &Y[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sx += X[i];
        sy += Y[i];
        sx2 += X[i] * X[i];
        sxy += X[i] * Y[i];
    }

    float m = (n * sxy - sx * sy) / (n * sx2 - sx * sx);
    float c = (sy - m * sx) / n;

    printf("Regression line equation is : y=%.4fx+%.4f", m, c);
}