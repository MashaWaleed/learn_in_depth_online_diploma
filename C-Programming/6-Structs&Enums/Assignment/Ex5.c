#include <stdio.h>

#define pi 3.14159
#define area(r) (pi * r *r)


int main() {
	int r;
	printf("Enter radius: ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &r);
	printf("area of circle: %.2f", area(r));

	return 0;
}
