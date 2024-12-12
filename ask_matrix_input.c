#include <stdio.h>
int main(){
    int a[4]; //define the size of the matrix 
    int sum=0; //we gave the sum as 0 
    printf("Enter the elements of the array: "); 
    for(int i=0; i<=3; i++){
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    printf("%d", sum);
    return 0;
}