//Header Files
#include<pthread.h>
#include<stdio.h>
#include<conio.h>

//Mutex initialization
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

//Funtion ProtoType
void* Sum(void* x);

//Main Function
int main()
{
    pthread_t thread[10];       //Creating Array of 10 Threads
	int i=0, j=0, total=0;
	int *temp=NULL;

	for(; i<10; i++)
	{
		int x=i+1;
		int k=x*1000;
		pthread_create(&thread[i], NULL,Sum,(void*)k);      //Create
	}

	for(; j<10; j++)
	{
		pthread_join(thread[j],((void*)&temp));     //join and Sum
		total+=(int)temp;
	}

	printf("Sum of 1st 10000 Numbers is: %d",total);
	return 0;
}

void* Sum(void* x)
{
	int End=(int)x, sum=0;
	int start= End-1000+1;
	int i=start;

	for(; i<=End; i++)
	{
	    pthread_mutex_lock(&mut);
		sum+=i;
	    pthread_mutex_unlock(&mut);
	}
	return sum;
}
