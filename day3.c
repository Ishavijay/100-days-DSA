//implement linear search to find key k in an array. Count and display the number of comparisons performed.
/*
Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)
*/
#include<stdio.h>
int main(){
int comparisons=0;
int n,key;
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
scanf("%d",&key);
for(int i=0;i<n;i++){
    comparisons++;
if(arr[i]==key){
    printf("Found at index %d\n",i);
    break;
}}

printf("Comparisons=%d",comparisons);
return 0;
}