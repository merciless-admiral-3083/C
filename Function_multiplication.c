#include<stdio.h>


int mult(int a,int b){
    int c;
    c=a*b;
    return c;
}

int main(){
    int x,y;
    x=10;
    y=20;
    int z=mult(x,y);
    printf("%d",z);
    return 0;
}