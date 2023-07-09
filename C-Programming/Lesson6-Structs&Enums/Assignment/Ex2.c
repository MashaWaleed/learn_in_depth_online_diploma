#include <stdio.h>
struct Distance {
	int feet;
	float inch;
};
int main() {
	struct Distance a,b;
	int sumFeet = 0; float sumInch = 0;
	printf("Enter info for 1st distance\n");
	printf("Enter feet: ");
	fflush(stdout);fflush(stdin);scanf("%d", &a.feet);
	printf("Enter inches: ");
	fflush(stdout);fflush(stdin);scanf("%f", &a.inch);

	printf("Enter info for 2nd distance\n");
	printf("Enter feet: ");
	fflush(stdout);fflush(stdin);scanf("%d", &b.feet);
	printf("Enter inches: ");
	fflush(stdout);fflush(stdin);scanf("%f", &b.inch);

	sumFeet = a.feet + b.feet;
	sumInch = a.inch + b. inch;
	if(sumInch >= 12){
		sumFeet++;
		sumInch -=12;
	}

	printf("sum of distances: %d'-%f\"",sumFeet, sumInch);

	return 0;
}
