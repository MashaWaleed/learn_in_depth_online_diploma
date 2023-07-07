#include <stdio.h>

void reverse(int a[], int s){
	int temp;
	for(int i = 0; i<s/2 ; i++){
		temp = a [i];
		a[i] = a[s-i-1];
		a[s-i-1] = temp;
	}
}

int main ()
{
	while(1){
	int s;
	int a[20];

	printf("\r\nEnter size of array: ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &s);
	printf("Enter nums: ");
	fflush(stdout);fflush(stdin);
	for(int i = 0 ; i< s; i++){
		scanf("%d", &a[i]);
	}
	reverse(a,s);
	printf("After reverse: ");
	for(int i = 0 ; i< s; i++){
		printf("%d ", a[i]);
	}
	}

	return 0;
}


