#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5  // Define buffer size

int buffer[BUFFER_SIZE]; // Shared buffer
int count = 0;          // Number of items in buffer

sem_t empty, full;      // Semaphores
pthread_mutex_t mutex;  // Mutex for synchronization

// Producer function
void *producer(void *arg) {
    int item = 1;
    while (1) {
        sem_wait(&empty);       // Wait if buffer is full
        pthread_mutex_lock(&mutex);  // Lock the buffer

        // Produce an item
        buffer[count] = item;
        printf("Producer produced: %d\n", item);
        item++;
        count++;

        pthread_mutex_unlock(&mutex); // Unlock buffer
        sem_post(&full);        // Signal that buffer is not empty

        sleep(1);
    }
}

// Consumer function
void *consumer(void *arg) {
    while (1) {
        sem_wait(&full);        // Wait if buffer is empty
        pthread_mutex_lock(&mutex);  // Lock the buffer

        // Consume an item
        int item = buffer[count - 1];
        printf("Consumer consumed: %d\n", item);
        count--;

        pthread_mutex_unlock(&mutex); // Unlock buffer
        sem_post(&empty);       // Signal that buffer is not full

        sleep(2);
    }
}

int main() {
    pthread_t prodThread, consThread;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE); // 'empty' counts empty slots
    sem_init(&full, 0, 0);            // 'full' counts filled slots
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prodThread, NULL, producer, NULL);
    pthread_create(&consThread, NULL, consumer, NULL);

    // Join threads
    pthread_join(prodThread, NULL);
    pthread_join(consThread, NULL);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
