#include<stdio.h>

struct richperson{
	char name[10];
	int age;
	long int networth;
};

struct queries{
	int maxpeople;
	int minage;
	int maxage;
};

void filt(struct richperson *people, long int NumPeople);

void InsertionSort(struct richperson *, long int);

void PrintSelectedPeo(struct richperson *people, int minage, int maxage, int maxpeople, int NumPeople);

int stringcmp(const char *,const char *);

int main(void){
	struct richperson people[100000];
	struct queries queries[1000];
	
	long int NumPeople, i;
	int NumQueries;
	
	scanf("%ld%d",&NumPeople,&NumQueries);
	for (i = 0; i < NumPeople; i++){
		scanf("%s", people[i].name);
		scanf("%d", &people[i].age);
		scanf("%ld", &people[i].networth);
	}
	
	filt(people, NumPeople);
	InsertionSort(people, NumPeople);
	
	for (i = 0; i < NumQueries; i++)
		scanf("%d%d%d", &queries[i].maxpeople, &queries[i].minage, &queries[i].maxage);
	
	for (i = 0; i < NumQueries; i++){
		printf("Case #%ld:\n", i + 1);
		PrintSelectedPeo(people, queries[i].minage, queries[i].maxage, queries[i].maxpeople, NumPeople);
	}
	
	return 0;
}

void InsertionSort(struct richperson *people, long int NumPeople){
	long int i, j;
	struct richperson Tmp;
	for (i = 0; i < NumPeople; i++){
		Tmp = people[i];
		for (j = i; j > 0; j--){
			if (people[j - 1].networth < Tmp.networth)
				people[j] = people[j - 1];
			else if (people[j - 1].networth > Tmp.networth)
				break;
			else if (people[j - 1].age > Tmp.age)
				people[j] = people[j - 1];
			else if (people[j - 1].age < Tmp.age)
				break;
			else if (stringcmp(people[j -1].name, Tmp.name) > 0)
				people[j] = people[j - 1];
			else
				break;
		}
		people[j] = Tmp;
	}
}

int stringcmp(const char *str1,const char *str2){
	while((*str1)&&(*str2)&&(*str1==*str2)){
		str1++;
		str2++;
	}
	return (int)(*str1-*str2);
}

void PrintSelectedPeo(struct richperson *people, int minage, int maxage, int maxpeople, int NumPeople){
	int i, j, k;
	j = 0;
	for (i = 0; i < NumPeople; i++){
		if (people[i].age >= minage && people[i].age <= maxage){
			k = 0;
			while(people[i].name[k] != '\0')
				printf("%c", people[i].name[k++]);
			printf(" %d %ld\n", people[i].age, people[i].networth);
			j++;
			if (j == maxpeople)
				break;
		}
	}
	if (!j)
		printf("None\n");
}

void filt(struct richperson *people, long int NumPeople){
	long int i, j;
	int age = people[0].age;
	int count = 0;
	struct richperson Tmp;
	for (i = 0; i < NumPeople; i++){
		Tmp = people[i];
		for (j = i; j > 0; j--){
			if (people[j - 1].age > Tmp.age)
				people[j] = people[j - 1];
			else if (people[j - 1].age < Tmp.age)
				break;
			else if (people[j - 1].networth < Tmp.networth)
				people[j] = people[j - 1];
			else if (people[j - 1].networth > Tmp.networth)
				break;
			else if (stringcmp(people[j - 1].name, Tmp.name) > 0)
				people[j] = people[j - 1];
			else
				break;
		}
		people[j] = Tmp;
	}
	for (i = 0; i < NumPeople; i++){
		if (age == people[i].age){
			count++;
			if (count >= 100){
				people[i].networth = -1000000;
			}
		}
		else{
			age = people[i].age;
			count = 0;
		}
	}
}