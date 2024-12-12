#include<stdio.h>
#include<conio.h>


int add(int a, int b){
    int sum;
    sum=a+b;
    return sum;

}

int main(){
    
    int x,y,z;
    x=10;
    y=11;
    z=add(x,y);
    printf("sum of %d and %d is %d", x,y,z);
    
    return 0;
    
}