#include <stdio.h>
int main(){
    int sum;
    int a[5]={1,2,3,4,5};
    for(int n=0; n<=4; n++){
        sum+=a[n];
    }
    printf("%d", sum);
   
}