#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = 0;
int rear = 0;
int count = 0;

void enqueue(int element) {
    if(count == MAX_SIZE) {
        printf("Queue is full. Cannot enqueue %d.\n", element);
        return;
    }
    queue[rear] = element;
    rear = (rear + 1) % MAX_SIZE;
    count++;
}

int dequeue() {
    if(count == 0) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int element = queue[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return element;
}

void display() {
    int i = front;
    for(int j = 0; j < count; j++) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display();

    printf("Dequeued: %d\n", dequeue());
 //   printf("Dequeued: %d\n", dequeue());
    enqueue(6);
    display();
    }
