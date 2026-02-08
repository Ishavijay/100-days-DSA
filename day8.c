/*Problem: Given integers a and b, compute a^b using recursion without using pow() function.*/
#include <Stdio.h>
int power(int a,int b){
    int result=1;
   for(int i=0;i<b;i++){
    result *=a;
   }
   return result;
}
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d",power(x,y));
}