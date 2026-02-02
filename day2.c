/* Write a C program to delete the element at a given 1-based
 position pos from an array of n integers. Shift remaining elements to the left.*/
 #include <stdio.h>
 int main(){
    int n,pos;
    //taking size of array
    scanf("%d",&n);
    int arr[n];
    //taking array elements
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        print("\t");
    }
    //taking the position of the element that needs to be deleted
    scanf("%d",&pos);
    //shifting the elements to left
    for(int i=pos-1;i<n-1;i++){
         arr[i]=arr[i+1];
    }
    n--;
    //printing the array
    for(int i=0;i<n;i++){
         printf("%d",arr[i]);
    }
    return 0;
}