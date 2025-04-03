#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t rw_mutex;  // Semaphore for writer access
sem_t mutex;     // Semaphore for reader counter update
int read_count = 0;  // Number of active readers
int data = 1;  // Shared resource

// Reader function
void *reader(void *arg) {
    int id = *(int *)arg;
    while (1) {
        sem_wait(&mutex);  // Lock reader count update
        read_count++;
        if (read_count == 1)
            sem_wait(&rw_mutex);  // First reader blocks writer
        sem_post(&mutex);

        // Reading section
        printf("Reader %d reads data: %d\n", id, data);
        sleep(1);

        sem_wait(&mutex);
        read_count--;
        if (read_count == 0)
            sem_post(&rw_mutex);  // Last reader releases writer
        sem_post(&mutex);

        sleep(2);
    }
}

// Writer function
void *writer(void *arg) {
    int id = *(int *)arg;
    while (1) {
        sem_wait(&rw_mutex);  // Lock resource for writer

        // Writing section
        data++;
        printf("Writer %d writes data: %d\n", id, data);
        sleep(2);

        sem_post(&rw_mutex);  // Release resource

        sleep(3);
    }
}

int main() {
    pthread_t r_threads[3], w_threads[2];
    int r_ids[3] = {1, 2, 3}, w_ids[2] = {1, 2};

    sem_init(&rw_mutex, 0, 1);  // Writer semaphore
    sem_init(&mutex, 0, 1);     // Reader counter semaphore

    // Create reader and writer threads
    for (int i = 0; i < 3; i++)
        pthread_create(&r_threads[i], NULL, reader, &r_ids[i]);
    for (int i = 0; i < 2; i++)
        pthread_create(&w_threads[i], NULL, writer, &w_ids[i]);

    // Join threads
    for (int i = 0; i < 3; i++)
        pthread_join(r_threads[i], NULL);
    for (int i = 0; i < 2; i++)
        pthread_join(w_threads[i], NULL);

    // Destroy semaphores
    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);

    return 0;
}
