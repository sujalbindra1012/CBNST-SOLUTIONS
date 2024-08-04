#include<stdio.h>

int main(){
    int n,i,j;
    printf("enter number of terms:");
    scanf("%d",&n);
    float X[n],Y[n],sum=0,term,x;
    printf("enter the values of X:");
    for(i=0;i<n;i++){
        scanf("%f",&X[i]);
    }
    printf("enter values of Y:");
    for(i=0;i<n;i++){
        scanf("%f",&Y[i]);
    }
    printf("enter value of x for which you want values of y:");
    scanf("%f",&x);
    printf("\n");
    for(i=0;i<n;i++){
        term=1;
        for(j=0;j<n;j++){
            if(i!=j){
                term=term*((x-X[j])/(X[i]-X[j]));
            }
        }
        sum=sum+term*Y[i];
    }
    printf("the value of y at given x=%g is %f",x,sum);
}