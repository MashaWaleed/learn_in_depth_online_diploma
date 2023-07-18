#include <stdio.h>

void count(int n){
	int count = 0;
	for(int i = 0; i < 32; i++){
		if((n>>i) &1){
			count++;
		}
	}
	printf("Count of ones is: %d", count);
}

int main ()
{
	while(1){
	int n;
	printf("\nEnter a num: ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &n);
	count(n);
	}
	return 0;
}

