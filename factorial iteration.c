#include<stdio.h>
int main()
{
    int i, number,fact=1;
    printf("enter the number:");
    scanf("%d",&number);
    for(i=1;i<=number;i++){
        fact=fact*i;
    }
    printf("factorial= %d",fact);
}
