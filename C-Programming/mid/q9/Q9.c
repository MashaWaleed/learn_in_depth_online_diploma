#include <stdio.h>
#include <string.h>

void reverse(char c[]){
	char r[30];
	int pos = 0;
	int i;
	for(i = 0; i<strlen(c); i++){
		if(c[i] == ' '){
			pos = i; break;
		}
	}
	i =0;

	while(c[pos + i + 1] != '\0'){
		r[i] = c[pos+1+i];
		i++;
	}
	r[i] = ' ';
	int k =0;
	while(c[k] != ' '){
		r[i+1] = c[k];
		i++;
		k++;
	}
	r[i+1] = '\0';
	printf("Reversed: %s", r);
}

int main ()
{
	while(1){

	char c[30];
	printf("\nEnter a name: ");
	fflush(stdout);fflush(stdin);
	gets(c);
	reverse(c);
	}

	return 0;
}




