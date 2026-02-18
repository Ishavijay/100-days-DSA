/*Problem: Given an array of integers, rotate the array to the right by k positions.*/
#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];

    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int k;
    scanf("%d",&k);

    k = k % n;   // important if k > n

    for(int i=0;i<k;i++){
        int last = arr[n-1];     // store last element

        for (int j=n-1;j>0;j--){
            arr[j] = arr[j-1];   // shift right
        }

        arr[0] = last;           // put last at front
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;
}
