#include<stdio.h>

void convertUpperTriangular(float matrix[3][4],int n){
    float ratio;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(j>i){
                ratio=matrix[j][i]/matrix[i][i];
                printf("Ratio :%f",ratio);
                for(int k = 0 ; k < n+1 ;k++){
                    matrix[j][k]=matrix[j][k]-(ratio*matrix[i][k]);
                }
                printf("Intermediate form:");
                for(int x = 0 ; x< n ; x++){
                    for(int y =0 ; y<n+1 ; y++){
                        printf("%.2f\n",matrix[x][y]);
                    }
                }
            }
        }
    }

}
void substitution(float matrix[3][4],float value[] , int n){
    float sum ;
    value[n-1]=matrix[n-1][n]/matrix[n-1][n-1];
    for(int i = n-2 ; i>=0 ; i--){
        sum=0;
        for(int j = i+1 ; j< n ; j++){
            sum+=matrix[i][j]*value[j];
        }
        value[i]=(matrix[i][n]-sum)/matrix[i][i];
    }

}

int main(){
    int n;
    printf("Enter the number of observations:");
    scanf("%d",&n);
    float X[n],Y[n],sx=0,sy=0,sxy=0,sx2=0,sx3=0,sx4=0,sx2y=0,value[3],matrix[3][4];
    printf("Enter the values of X :");
    for(int i = 0 ; i < n ; i++){
        scanf("%f",&X[i]);
    }
    printf("Enter the values of Y :");
    for(int i = 0 ; i < n ; i++){
        scanf("%f",&Y[i]);
    }
    for(int i = 0 ; i < n ; i++){
        sx+=X[i];
        sy+=Y[i];
        sx2+=X[i]*X[i];
        sx3+=X[i]*X[i]*X[i];
        sx4+=X[i]*X[i]*X[i]*X[i];
        sxy+=X[i]*Y[i];
        sx2y+=X[i]*X[i]*Y[i];
    }
    matrix[0][0]=sx2;
    matrix[0][1]=sx;
    matrix[0][2]=n;
    matrix[0][3]=sy;
    matrix[1][0]=sx3;
    matrix[1][1]=sx2;
    matrix[1][2]=sx;
    matrix[1][3]=sxy;
    matrix[2][0]=sx4;
    matrix[2][1]=sx3;
    matrix[2][2]=sx2;
    matrix[2][3]=sx2y;

    convertUpperTriangular(matrix,3);
    substitution(matrix,value,3);

    printf("Equation is y=%.2fx^2+%.2fx+%.2f",value[0],value[1],value[2]);
    
}