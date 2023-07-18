#include<stdio.h>


int main()
{	
	printf("number of elements: ");
	int n, arr[15], *ptr = (int*)arr;
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		printf("Enter element number %d:", i+1);
		scanf("%d", ptr);ptr++;
		printf("\r\n");
	}
	ptr--;
	for(int i = n ; i>0 ; i--){
		printf("element %d is :%d \r\n",i,*ptr);ptr--;
	}
	return 0;
}
