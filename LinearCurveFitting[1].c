#include<stdio.h>

int main(){
    int n;
    printf("enter the number of observations:");
    scanf("%d",&n);
    float X[n],Y[n],a,b;
    printf("Enter the values of X:");
    for(int i = 0 ; i< n ; i++){
        scanf("%f",&X[i]);
    }
    printf("Enter the values of Y:");
    for(int i = 0 ; i< n ; i++){
        scanf("%f",&Y[i]);
    }
    float sum1=0,sum2=0,sum3=0,sum4=0;
    for(int i = 0 ; i< n ; i++){
        sum1=sum1+X[i];
        sum2=sum2+Y[i];
        sum3=sum3+X[i]*Y[i];
        sum4=sum4+X[i]*X[i];
    }

    float matrix[2][3];
    matrix[0][0]=n;
    matrix[0][1]=sum1;
    matrix[0][2]=sum2;
    matrix[1][0]=sum1;
    matrix[1][1]=sum4;
    matrix[1][2]=sum3;
    
    int ratio = matrix[1][0]/matrix[0][0];
    for(int i = 0 ; i< 3; i++){
        matrix[1][i]=matrix[1][i]-ratio*matrix[0][i];
    }
    printf("Upper Triangle Matrix:");
    for(int i = 0 ; i< 2 ; i++){
        for(int j = 0 ; j<3 ; j++){
            printf("%.2f\n",matrix[i][j]);
        }
    }
    b= matrix[1][2]/matrix[1][1];
    a=(matrix[0][2]-matrix[0][1]*b)/matrix[0][0];

    printf("Intercept =%.2f , Slope=%.2f",a,b);

    printf("Equation of line : y = %.2f+%.2fx",a,b);


}