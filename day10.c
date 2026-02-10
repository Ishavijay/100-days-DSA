#include <stdio.h>
#include <string.h>
int main(){
    char s[100];
    printf("Enter the string:");
    scanf("%s",s);
    int left=0;
    int right=strlen(s)-1;
    while(left<right){
        if(s[right]!=s[left]){
            printf("No");
            return 0;
        }
        
    left++;
    right--;
}
    printf("yes");
    return 0;
    }