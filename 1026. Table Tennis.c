# include <stdio.h>
# include <stdlib.h>
#define CLOSETIME 46800
#define NOTABLE -1
#define YES 1
#define NO 0

struct tennis{
	int arrive_t;
	int play_t;
	int IsVIP;
	int serve_t;
};

struct table{
	int IsVIP;
	int available_t;
	int servedpeo;
};

struct tennis *waiteline[10000];
struct table tableline[100];

void sort(int );
int findtable(int);
int findtableingiventime(int, int, int);
void findVIP(int, int, int);

int main(void){
	int numplayer;
	int hour, minute, second;
	int numtable, numviptable, viptablenum;
	int i, j, smalltable;
	struct tennis *tmp;
	
	scanf("%d", &numplayer);
	for (i = 0; i < numplayer; i++){
		waiteline[i] = (struct tennis *)malloc(sizeof(struct tennis));
		scanf("%d:%d:%d %d %d", &hour, &minute, &second, &(waiteline[i]->play_t), &(waiteline[i]->IsVIP));
		waiteline[i]->arrive_t = (hour-8)*3600 + minute*60 + second;
		waiteline[i]->play_t = waiteline[i]->play_t * 60;
		if (waiteline[i]->play_t > 7200)
			waiteline[i]->play_t = 7200;
	}
	sort(numplayer);
	
	scanf("%d %d", &numtable, &numviptable);
	for (i = 0; i < numviptable; i++){
		scanf("%d", &viptablenum);
		tableline[viptablenum-1].IsVIP = YES;
	}
	
	for (i = 0; i < numplayer; i++){
		// if (waiteline[i]->arrive_t < 0)
			// continue;
		if (waiteline[i]->arrive_t >= CLOSETIME)
			break;
		smalltable = findtable(numtable);
		if (smalltable == NOTABLE)
			break;
		if (tableline[smalltable].available_t < waiteline[i]->arrive_t){ 
			smalltable = findtableingiventime(numtable, waiteline[i]->arrive_t, waiteline[i]->IsVIP);
			waiteline[i]->serve_t = waiteline[i]->arrive_t;
			tableline[smalltable].available_t = waiteline[i]->arrive_t + waiteline[i]->play_t;
			tableline[smalltable].servedpeo++;
		}
		else{
			if (tableline[smalltable].IsVIP){
				findVIP(i, numplayer, tableline[smalltable].available_t);
				waiteline[i]->serve_t = tableline[smalltable].available_t;
				tableline[smalltable].available_t += waiteline[i]->play_t;
				tableline[smalltable].servedpeo++;
			}
			else{
				if (waiteline[i]->IsVIP)
					smalltable = findtableingiventime(numtable, tableline[smalltable].available_t, waiteline[i]->IsVIP);
				waiteline[i]->serve_t = tableline[smalltable].available_t;
				tableline[smalltable].available_t += waiteline[i]->play_t;
				tableline[smalltable].servedpeo++;
			}
		}
		
	}
	
	for (j = 0; j < i; j++){
		// if (waiteline[j]->arrive_t < 0)
			// continue;

		hour = (waiteline[j]->arrive_t + 8*3600.0)/3600 ;
		minute = (waiteline[j]->arrive_t - (hour-8)*3600)/60;
		second = waiteline[j]->arrive_t - (hour-8)*3600 - minute*60;
		printf("%02d:%02d:%02d ", hour, minute, second);
		hour = (waiteline[j]->serve_t + 8*3600)/3600;
		minute = (waiteline[j]->serve_t - (hour-8)*3600.0)/60;
		second = waiteline[j]->serve_t - (hour-8)*3600 - minute*60;
		printf("%02d:%02d:%02d ", hour, minute, second);
		printf("%d\n", (waiteline[j]->serve_t - waiteline[j]->arrive_t +30)/60);
	}
	for (j = 0; j < numtable-1; j++){
		printf("%d ", tableline[j].servedpeo);
	}
	printf("%d\n", tableline[j].servedpeo);
	
	return 0;
}

void sort(int num){
	struct tennis *Tmp;
	int i, j;
	for (i = 0; i < num; i++){
		Tmp = waiteline[i];
		for (j = i; j > 0 && waiteline[j-1]->arrive_t > Tmp->arrive_t; j--)
			waiteline[j] = waiteline[j - 1];
		waiteline[j] = Tmp;
	}
}

int findtable(int num){
	int tmp, i;
	
	for (tmp = i = 0; i < num; i++)
		if (tableline[tmp].available_t > tableline[i].available_t)
			tmp = i;
	if (tableline[tmp].available_t >= CLOSETIME)
		return NOTABLE;
	return tmp;
}

int findtableingiventime(int num, int time, int VIP){
	int i;
	if (VIP){
		for (i = 0; i < num; i++){
			if ((tableline[i].available_t <= time) && tableline[i].IsVIP)
			return i;
		}
	}
	
	for (i = 0; i < num; i++)
		if (tableline[i].available_t <= time)
			break;
	return i;
}

void findVIP(int initial, int num, int time){
	struct tennis *tmp;
	int i, j;
	for (i = initial; i < num; i++){
		if (waiteline[i]->arrive_t >= time)
			break;
		else{
			if(waiteline[i]->IsVIP){
				tmp = waiteline[i];
				for(j = i; j > initial; j--)
					waiteline[j] = waiteline[j-1];
				waiteline[initial] = tmp;
				break;
			}
		}
	}
}



