#include<stdio.h>
#include<conio.h>
int main(){
    int n, sum_even=0, sum_odd=0;
   
    do{
         printf("Enter a number: ");
        scanf("%d", &n);
        if(n%2==0){
            sum_even +=n;   //it will keep on asking and adding for numbers until i type the number as -1
        }
        else sum_odd += n;

    }
    while (n!= -1);
    printf("Sum of even number %d and sum of odd %d ", sum_even, sum_odd);
    return 0;
}