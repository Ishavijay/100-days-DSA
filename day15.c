/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. 
The primary diagonal consists of elements where row index equals column index.*/
#include <stdio.h>
int main(){
    int sum=0;
    int m,n;
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\n");
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                sum=sum+arr[i][j];
            }
        }
    }
    printf("%d",sum);
}