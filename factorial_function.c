#include <stdio.h>

int fact(int t){
    int k=1,i;
    for(i=1;i<=t;i++){
        k=k*i;
    }
    return k;
}

int main() {
    int n=4,p;
    p=fact(n);
    printf("%d",p);
    return 0;
}
