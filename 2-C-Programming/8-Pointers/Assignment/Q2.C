#include<stdio.h>


int main()
{
	char alpha [26];
	char *p = (char *)&alpha;
	for(int i = 0; i<26; i++){
		*p = 'A'+i;
		p++;
	}
	p = alpha;
	for (int i =0 ; i<26; i++){
		printf("%c ", *p++);
	}
	return 0;
}
