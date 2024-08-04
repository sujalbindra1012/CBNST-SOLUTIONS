#include <stdio.h>
#define f(x, y) ((y - x) / (y + x))

int main()
{
    float x0, y0, xn, yn, slope, h;
    printf("enter initial conditions x0 and y0:");
    scanf("%f %f", &x0, &y0);
    printf("enter value of x for which you want value of y :");
    scanf("%f", &xn);
    int n;
    printf("enter number of steps");
    scanf("%d", &n); 
    h = (xn - x0) / n;
    printf("\nx0\ty0\tslope\tyn");
    for (int i = 0; i < n; i++)
    {
        slope = f(x0, y0);
        yn = y0 + h * slope;
        printf("\n%.2f\t%.3f\t%.4f\t%.4f\n", x0, y0, slope, yn);
        y0 = yn;
        x0 = x0 + h;
    }
    printf("The value of y for the given x=%.2f is %.4f", xn, yn);
    return 0;
}
