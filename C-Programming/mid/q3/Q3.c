#include <stdio.h>

void primes(int n, int a){

	for(int i = n; i<=a; i++){
		int counter  = 0;
		for(int j = 1; j<=i; j++){
			if(i%j == 0){
				counter++;
			}
		}
		if(counter <= 2) printf("%d ", i);
	}
}

int main ()
{
	while(1){
	int n, a;
	printf("\nEnter two nums: ");
	fflush(stdout);fflush(stdin);
	scanf("%d %d", &n, &a);
	primes(n,a);
	}
	return 0;
}

