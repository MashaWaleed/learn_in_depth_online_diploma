#include <stdio.h>

double sqrt(int n){
	double i;
	for( i = 0.0001; i * i < n; i+= 0.0001);
	return(i);

}

int main ()
{
	while(1){
	int n;
	printf("Enter a num: ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &n);
	printf("%.3f\n", sqrt(n));
	}
	return 0;
}




