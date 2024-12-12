//use & when using scanf
//use %f for float
#include<stdio.h>
#include<conio.h>



int main(){

int N, rev, r;
rev=0;

printf("Enter the value of N: ");
scanf("%d",&N);  
while (N>0){ //till the time N is greater than 0, you divide N by 10 and take the integer input
    r=N%10;
    rev=rev*10+r; //let say we had 45 and we got 5 from there, so we did 0*10+5, then we got 4 then we do 5*10+4 i.e. 54
    N=N/10;  //it will remove last digit as integer i.e. it will remove 5 from 45 to help us read things
    //in other words it wwill help satisfy while condition by making N=0 by dividing numbers again and again
}
printf("Reversed number is %d ",rev);



    return 0;
}