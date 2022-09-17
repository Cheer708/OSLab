#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
int Csum;
void *runner(void *param);
int main(int argc , char *argv[]){
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid , &attr , runner ,argv[1]);
   
	int upper = atoi(argv[1]);
	int Msum = 0;
	if(upper > 0){
		for(int i = 0;i <= upper;i++)
			Msum += i;
	}
	pthread_join(tid,NULL);
	printf("Csum - Msum = %d\n" , Csum - Msum);
	return 0;
}
void *runner(void *param){
	int upper = atoi(param);
	Csum = 0;
	if(upper > 0){
		for(int i = 0;i <= upper*2;i++)
			Csum += i;
	}
	pthread_exit(0);
}
