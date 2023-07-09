#include <stdio.h>
struct Complex {
	float real;
	float imaginary;
};
struct Complex add(struct Complex a,struct Complex b){
	struct Complex result;
	result.real = a.real +b.real; result.imaginary = a.imaginary + b.imaginary;
	return result;
}
int main() {
	struct Complex a,b,r;
	printf("Enter info for 1st Complex\n");
	printf("Enter real num: ");
	fflush(stdout);fflush(stdin);scanf("%f", &a.real);
	printf("Enter imaginary num: ");
	fflush(stdout);fflush(stdin);scanf("%f", &a.imaginary);

	printf("Enter info for 2st Complex\n");
	printf("Enter real num: ");
	fflush(stdout);fflush(stdin);scanf("%f", &b.real);
	printf("Enter imaginary num: ");
	fflush(stdout);fflush(stdin);scanf("%f", &b.imaginary);
	r = add(a,b);
	printf("%.2f+%.2fi", r.real, r.imaginary);



	return 0;
}
