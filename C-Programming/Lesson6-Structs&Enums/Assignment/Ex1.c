#include <stdio.h>
struct Sstudent {
	char sname[20];
	int srnum;
	float smark;

};
int main() {
	struct Sstudent A;
	printf("Enter student name: ");
	fflush(stdout);
	fflush(stdin);
	gets(A.sname);
	printf("Enter student roll number: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d",&A.srnum);
	printf("Enter student mark: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f",&A.smark);
	printf("\nstudent name: %s", A.sname);
	printf("\nstudent roll: %d", A.srnum);
	printf("\nstudent mark: %.2f", A.smark);
	return 0;
}
