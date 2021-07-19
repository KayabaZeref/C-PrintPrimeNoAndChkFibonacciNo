#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu()
{
	printf("1- The first primes");
	printf("\n2- Fibonacci element");
	printf("\n3- Sum of digits");
	printf("\nChoose: ");
	int choice;
	scanf("%d",&choice);
	return choice;
}

void printPrimes(int n){
	int value;
	int count;
	value=2;
	count=0;
	while(count<n)
	{
		if (isPrime(value)==1)
		{
			printf("%d ",value);
			count++;
		}
		value++;
	}
	printf("\n");
}

int isPrime(int n) {
    int d = sqrt(n);
	int i;
	for (i=2; i<=d; i++){
		if  (n%i == 0) 
		{
			return 0;
		}
    }
    return 1; 
}

int isFibo(int n){
	int value,t1,t2;
	value=t1=t2=1;
	if(n<1) 
	{
		return 0;
	}
	while(value<n)
	{
		value=t1+t2;
		t1=t2;
		t2=value;
	}
	if(value==n)
	{
		return 1;
	}
	return 0;
}
int sumDigits(int n){
	int sum=0;
	while(n>0)
	{
		sum=sum+n%10;
		n=n/10;
	}
	return sum;
}
int main(int argc, char *argv[]) {
	int choice;
	int num;
	do
	{
		choice= menu();
		switch (choice)
		{
			case 1:
				do
				{
					printf("\nNumber of primes: ");
					scanf("%d",&num);
				}
				while(num<=0);
				printPrimes(num);
				break;
			case 2:
				printf("\nNumber tested: ");
				scanf("%d",&num);
				if(isFibo(num)==1)
				{
					printf("It's a Fibonacci term.\n");
				}
				else 
				{
					printf("It's not a Fibonacci term.\n");
				}
				break;
			case 3:
				do
				{
					printf("\nEnter an integer (Positive): ");
					scanf("%d",&num);
				}
				while(num<=0);
				printf("Sum of it's digits:%d",sumDigits(num));
				break;
			default:	printf("\n End \n");
						break;		
		}	
	}
	while(choice>0 && choice <3);
	return 0;
}
