#include<stdio.h>

int abc(int a){
    int i=0;
    if(a>0){
        abc(a-1);
    }
    printf("%d",a);
}

int main(){
    int g,k;
    k=5;
    g=abc(k);
    
}