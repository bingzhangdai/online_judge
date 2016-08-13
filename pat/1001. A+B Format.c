#include <stdio.h>

int main(void){
	int a, b, sum;
	int i = 0, flag = 1;
	int printsum[10];
	
	scanf("%d", &a);
	scanf("%d", &b);
	sum = a + b;
	if(sum == 0){
		printf("0\n");
		return 0;
	}
	while(sum != 0){
		if(sum < 0){
			printsum[i++] = -sum % 1000;
			sum /= 1000;
		}
		else{
			printsum[i++] = sum % 1000;
			sum /= 1000;
		}
	}
	
	if(a + b < 0)
		printf("%c", '-');
	printf("%d", printsum[--i]);
	while(i > 1){
		printf(",%03d", printsum[--i]);
	}
	if(i == 1)
		printf(",%03d\n", printsum[0]);
	return 0;
}
