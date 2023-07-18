#include <stdio.h>

char sumDigit(int n){
	int sum = 0;
	while(n!=0){
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main ()
{
	int n;
	printf("Enter a num: ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &n);
	printf("%d", sumDigit(n));
	return 0;
}
