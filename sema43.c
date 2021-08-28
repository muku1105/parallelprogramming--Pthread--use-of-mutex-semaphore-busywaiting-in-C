#include <stdio.h>                                        
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include<time.h>
long thread_count;
long long n=40000;
double a=0;
double b=2;
long double h;
long long trap_count;
sem_t sem;

long double sum;
void* sump(void* rank);
int main(int argc, char* argv[])
{
    long thread;
    thread_count = atoll(argv[1]);
    pthread_t* thread_handles;
    
    sem_init(&sem, 0, 1);
    

    thread_handles = (pthread_t*) malloc (thread_count*sizeof(pthread_t));
    sum = 0.0;
    h = (long double)(b-a)/n;
    trap_count = n/thread_count;

    clock_t begin = clock();
	printf("hello from main thread");
    for (thread = 0; thread < thread_count; thread++)
        pthread_create(&thread_handles[thread], NULL, sump, (void*)thread);

	


    for (thread = 0; thread < thread_count; thread++)
        pthread_join(thread_handles[thread], NULL);
    clock_t end = clock();
    double elapsed = (double)(end - begin)/CLOCKS_PER_SEC;

    sum = h*sum;
    printf("n = %lld\n", n);
    printf("   Our estimate of area = %f\n", (double)sum);
    printf("The elapsed time is %f seconds\n", elapsed);
    free(thread_handles);

    return 0;
}

void* sump(void* rank) {
    
long my_rank = (long) rank;
    long double x;
    long double my_sum = 0.0;
    long double start = a+trap_count*my_rank*h;
    long double end = a+trap_count*(my_rank+1)*h;

    my_sum = (start*start +end*end)/2.0;
    for (long long i = 1; i <= trap_count; i++)
    {
        x = start+i*h;
        my_sum +=x*x;
    }

    sem_post(&sem);
    sum += my_sum;
    sem_wait(&sem);

    return NULL;
}                                                                                                                                                                                                                                                                                                                    