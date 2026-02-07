/*Problem: Write a recursive function fib(n) to compute 
the n-th Fibonacci number where fib(0)=0 and fib(1)=1.*/
#include <Stdio.h>
int fibo(int n){
    if (n<=1){
        return n;
    }
    else{
        return fibo(n-1)+fibo(n-2);
    }
}
int main(){
    int limit;
    scanf("%d",&limit);
    printf("%d",fibo(limit));
    return 0;
}