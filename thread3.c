#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define N 20

int array[N]; // Shared array
int count = 0; // Counter for number of items in the array

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t producer_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t consumer_cond = PTHREAD_COND_INITIALIZER;

// Producer function
void *producer() {
    for (int i = 0; i < N; i++) {
        pthread_mutex_lock(&mutex);
        if (count == N) {
            printf("\nProducer: Array is full, waiting for consumer to consume.\n");
            pthread_cond_wait(&producer_cond, &mutex);
        }
        array[count++] = i; // Produce item
        printf("\nProducer: Produced item %d, count = %d\n", i, count);
        if (count == 1) { // Signal consumer if array was empty
            printf("\nProducer: Signaling consumer.\n");
            pthread_cond_signal(&consumer_cond);
        }
        pthread_mutex_unlock(&mutex);
        sleep(1); // Simulate production time
    }
    return NULL;
}

// Consumer function
void *consumer() {
    for (int i = 0; i < N; i++) {
        pthread_mutex_lock(&mutex);
        if (count == 0) {
            printf("\nConsumer: Array is empty, waiting for producer to produce.\n");
            pthread_cond_wait(&consumer_cond, &mutex);
        }
        int item = array[--count]; // Consume item
        printf("\nConsumer: Consumed item %d, count = %d\n", item, count);
        if (count == N - 1) { // Signal producer if array was full
            printf("\nConsumer: Signaling producer.\n");
            pthread_cond_signal(&producer_cond);
        }
        pthread_mutex_unlock(&mutex);
        sleep(2); // Simulate consumption time
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Creating producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Waiting for threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}
