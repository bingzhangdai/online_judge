#include <stdio.h>
#include <stdlib.h>


struct poly{
	int exponent;
	double coefficient;
	struct poly *next;
};

int addpoly(struct poly *, struct poly *, struct poly *);

int main(void){
	int k1, k2;
	int i;
	
	struct poly *poly1, *poly2, *tmp, *result;
	poly1 = (struct poly *) malloc(sizeof(struct poly));
	poly2 = (struct poly *) malloc(sizeof(struct poly));
	if(poly1 == NULL || poly2 == NULL)
		return -1;
	poly1->next = NULL;
	poly2->next = NULL;
	
	scanf("%d", &k1);
	tmp = poly1;
	for(i = 0; i < k1; i++){
		scanf("%d", &tmp->exponent);
		scanf("%lf", &tmp->coefficient);
		if(k1 - i > 1){
			tmp->next = (struct poly *) malloc(sizeof(struct poly));
			if(tmp->next == NULL)
				return -1;
			tmp = tmp->next;
			tmp->next = NULL;
		}
	}
	scanf("%d", &k2);
	tmp = poly2;
	for(i = 0; i < k2; i++){
		scanf("%d", &tmp->exponent);
		scanf("%lf", &tmp->coefficient);
		if(k2 - i > 1){
			tmp->next = (struct poly *) malloc(sizeof(struct poly));
			if(tmp->next == NULL)
				return -1;
			tmp = tmp->next;
			tmp->next = NULL;
		}
	}
	
	tmp = result = (struct poly *) malloc(sizeof(struct poly));
	
	if(result == NULL)
		return -1;
	result->next = NULL;
	
	i = addpoly(tmp, poly1, poly2);
	
	printf("%d", i);
	if(i != 0)
		while(result != NULL){
			printf(" %d", result->exponent);
			printf(" %.1lf", result->coefficient);
			result = result->next;
		}
/*	else*/			/* don't need to */
/*		printf(" 0 0.0");*/
	printf("\n");
	return 0;
}


int addpoly(struct poly *tmp, struct poly *poly1, struct poly *poly2){
	int i = 0;
	while(poly1 != NULL || poly2 != NULL){
		if(poly1 == NULL)
			while(poly2 != NULL){
				if(i){
					tmp->next = (struct poly *) malloc(sizeof(struct poly));
					if(tmp->next == NULL)
						return -1;
					tmp = tmp->next;
					tmp->next = NULL;
				}
				tmp->exponent = poly2->exponent;
				tmp->coefficient = poly2->coefficient;
				i++;
				poly2 = poly2->next;
			}
		else if(poly2 == NULL)
			while(poly1 != NULL){
				if(i){
					tmp->next = (struct poly *) malloc(sizeof(struct poly));
					if(tmp->next == NULL)
						return -1;
					tmp = tmp->next;
					tmp->next = NULL;
				}
				tmp->exponent = poly1->exponent;
				tmp->coefficient = poly1->coefficient;
				i++;
				poly1 = poly1->next;
			}
		else{
			if(poly1->exponent == poly2->exponent){
				if(poly1->coefficient + poly2->coefficient == 0){}
				else{
					if(i){
						tmp->next = (struct poly *) malloc(sizeof(struct poly));
						if(tmp->next == NULL)
							return -1;
						tmp = tmp->next;
						tmp->next = NULL;
					}
					tmp->exponent = poly1->exponent;
					tmp->coefficient = poly1->coefficient + poly2->coefficient;
					i++;
				}
				poly1 = poly1->next;
				poly2 = poly2->next;
			}
			else if(poly1->exponent > poly2->exponent){
				if(i){
					tmp->next = (struct poly *) malloc(sizeof(struct poly));
					if(tmp->next == NULL)
						return -1;
					tmp = tmp->next;
					tmp->next = NULL;
				}
				tmp->exponent = poly1->exponent;
				tmp->coefficient = poly1->coefficient;
				i++;
				poly1 = poly1->next;
			}
			else{
				if(i){
					tmp->next = (struct poly *) malloc(sizeof(struct poly));
					if(tmp->next == NULL)
						return -1;
					tmp = tmp->next;
					tmp->next = NULL;
				}
				tmp->exponent = poly2->exponent;
				tmp->coefficient = poly2->coefficient;
				i++;
				poly2 = poly2->next;
			}
		}
	}
	return i;
}


