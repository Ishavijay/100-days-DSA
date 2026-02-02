/*Write a C program to insert an element x at a given 1-based position pos in 
an array of n integers. Shift existing elements to the right to make space*/
#include <stdio.h>
int main(){
    int n,pos,value;
    //taking size of array
    scanf("%d",&n);
    //taking elements of the array
    int arr[n+1];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        printf("\t");
    }
    //taking the position of the rray
    scanf("%d",&pos);
    //taking the value 
    scanf("%d",&value);
    //inserting the element
    for(int i=n;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=value;
    n++;
    //printing the array
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
        printf("\t");
    }
    return 0;
}