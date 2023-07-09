#include <stdio.h>
struct Sstudent {
	char sname[20];
	int srnum;
	float smark;

};
int main() {
	struct Sstudent s[10];
	for (int i = 0; i < 10; i++) {
		printf("\nEnter student %d name: ", i + 1);
		fflush(stdout);
		fflush(stdin);
		gets(s[i].sname);
		printf("Enter student %d roll number: ", i + 1);
		fflush(stdout);
		fflush(stdin);
		scanf("%d", &s[i].srnum);
		printf("Enter student %d mark: ", i + 1);
		fflush(stdout);
		fflush(stdin);
		scanf("%f", &s[i].smark);
	}
	for (int i = 0; i < 10; i++) {
		printf("\nStudent no. %d inf0: \n", i + 1);
		printf("\nstudent name: %s", s[i].sname);
		printf("\nstudent roll: %d", s[i].srnum);
		printf("\nstudent mark: %.2f", s[i].smark);
	}

	return 0;
}
