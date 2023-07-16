#include<stdio.h>


int main()
{
	int m = 29;
	int *ab  = &m;
	printf("Address of m: 0x%x\nContent of m:%d\r\n", &m, m);
	printf("Address of ab: 0x%x\nContent of ab:%d\r\n", ab, *ab);
	m = 34;
	printf("Address of ab: 0x%x\nContent of ab:%d\r\n", ab, *ab);
	*ab = 7;
	printf("Address of m: 0x%x\nContent of m:%d\r\n", &m, m);
	return 0;
}
