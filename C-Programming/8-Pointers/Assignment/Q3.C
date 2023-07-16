#include<stdio.h>
#include<string.h>

int main()
{	
	char str[20];
	printf("Enter a string: ");
	scanf("%s", str);
	char * strp =(char *) &str[strlen(str)-1];
	for(int i = 0 ; i< strlen(str); i++){
		printf("%c", *strp--);
	}
	return 0;
}
