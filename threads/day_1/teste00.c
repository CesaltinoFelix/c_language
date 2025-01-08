#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* message()
{
	printf("Hey, Cesaltino Felix!!!\n");
	sleep(2);
	printf("Its everything fine?\n");
}

int main(void)
{
	pthread_t t1, t2;
	if(pthread_create(&t1, NULL, &message, NULL) != 0)
	{
		printf("pthread_create error!");
		return 1;
	}
	if(pthread_create(&t2, NULL, &message, NULL) != 0)
	{
		printf("pthread_create error!");
		return 1;
	}
	if(pthread_join(t1, NULL) != 0)
	{
		printf("pthread_join error!");
		return 2;
	}
	if(pthread_join(t2, NULL) != 0)
	{
		printf("pthread_join error!");
		return 2;
	}

	return (0);
}
