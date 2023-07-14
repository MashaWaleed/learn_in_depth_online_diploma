#include<stdio.h>

struct Semployee{
	char name[20];
	int id;
};

int main()
{	
	struct Semployee a = {"Mohamed", 123},b ={"Alex", 1002},c;
	struct Semployee* arr[3] ={&a,&b,&c};
	struct Semployee (*(*p)[3]) = &arr;

	printf("Employee name: %s\r\n",(*(*p+1))->name);
	printf("Employee id: %d\r\n",(*(*p+1))->id);

	return 0;
}
