#include <stdio.h>

void reverse(int n){
	if(n == 0) return;
	printf("%d", n%10);
	reverse(n/=10);
}

int main ()
{
	while(1){
	int n;
	printf("\nEnter a num: ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &n);
	reverse(n);
	}
	return 0;
}

