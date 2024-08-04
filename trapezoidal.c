#include <stdio.h>

float f(float x)
{
    return 1 / (1 + (x * x));
}

int main()
{
    float a, b, i, sum = 0, h;
    printf("enter value of a and b:");
    scanf("%f %f", &a, &b);
    int n;
    printf("enter value of intervals:");
    scanf("%d", &n);
    h = (b - a) / n;
    sum = f(a) + f(b);
    for (i = a + h; i < b; i = i + h)
    {
        sum = sum + 2 * f(i);
    }
    sum = (h * sum) / 2;
    printf("value of integral is :%f", sum);
}