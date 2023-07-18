#include <stdio.h>

void unique(int a[], int s){
	int num = 0;
	for(int i = 0; i < s; i++){
		num ^= a[i];
	}
	printf("The unique number is: %d", num);
}

int main ()
{
	while(1){
	int s;
	int a [20];

	printf("\r\nEnter size of array: ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &s);
	printf("Enter nums: ");
	fflush(stdout);fflush(stdin);
	for(int i = 0 ; i< s; i++){
		scanf("%d", &a[i]);
	}
	unique(a,s);
	}
	return 0;
}
