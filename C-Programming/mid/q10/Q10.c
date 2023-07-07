#include <stdio.h>
#include <string.h>

void count(int n){
	int flag = 0;
	int count = 0;
	int max = 0;
	for(int i = 0; i<16; i++){
		if(((n>>i) & 1 )== 0){
			flag = 1;
			continue;
		}
		while(flag == 1 && ((n>>i) & 1)){
			count++;
			i++;
			if(((n>>i) & 1) == 0){
				flag = 0;
				i--;
			}
		}
		if(count > max) max = count;
		count = 0;
	}
	printf("The max is :%d", max);
}

int main ()
{
	while(1){

	int n;
	printf("\nEnter a num: ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &n);
	count(n);
	}

	return 0;
}
