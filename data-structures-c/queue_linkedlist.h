// queue_array.h
#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

// ���� ť ����ü
typedef struct Queue {
    int* data;      // ������ �迭
    int front;      // ť�� ��
    int rear;       // ť�� ��
    int capacity;   // ť �뷮
    int size;       // ���� ť ũ��
} Queue;

// �Լ� ������Ÿ��
Queue* create_queue(void);
int enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int is_empty(Queue* queue);
int is_full(Queue* queue);
int get_size(Queue* queue);
void print_queue(Queue* queue);
void free_queue(Queue* queue);

#endif

// queue_array.c
#include "queue_array.h"

// ť ����
Queue* create_queue(void) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("ť �޸� �Ҵ� ����\n");
        return NULL;
    }

    queue->data = (int*)malloc(sizeof(int) * INITIAL_CAPACITY);
    if (queue->data == NULL) {
        printf("�迭 �޸� �Ҵ� ����\n");
        free(queue);
        return NULL;
    }

    queue->front = 0;
    queue->rear = -1;
    queue->capacity = INITIAL_CAPACITY;
    queue->size = 0;
    return queue;
}

// ������ ���� (enqueue)
int enqueue(Queue* queue, int data) {
    if (queue == NULL) return -1;

    if (is_full(queue)) {
        printf("ť�� ���� ��\n");
        return -1;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = data;
    queue->size++;
    return 0;
}

// ������ ���� �� ��ȯ (dequeue)
int dequeue(Queue* queue) {
    if (queue == NULL || is_empty(queue)) {
        printf("ť�� �������\n");
        return -1;
    }

    int data = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return data;
}

// ť�� ����ִ��� Ȯ��
int is_empty(Queue* queue) {
    return (queue == NULL || queue->size == 0);
}

// ť�� ���� ���� Ȯ��
int is_full(Queue* queue) {
    return (queue != NULL && queue->size == queue->capacity);
}

// ť ũ�� ��ȯ
int get_size(Queue* queue) {
    return (queue == NULL) ? 0 : queue->size;
}

// ť ���� ���
void print_queue(Queue* queue) {
    if (queue == NULL || is_empty(queue)) {
        printf("ť�� �������\n");
        return;
    }

    printf("ť ���� (front -> rear): ");
    int index = queue->front;
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[index]);
        index = (index + 1) % queue->capacity;
    }
    printf("\n");
}

// �޸� ����
void free_queue(Queue* queue) {
    if (queue != NULL) {
        if (queue->data != NULL) {
            free(queue->data);
        }
        free(queue);
    }
}

// main.c for queue test
#include "queue_array.h"

int main() {
    printf("=== ���� ť �׽�Ʈ ===\n\n");

    Queue* queue = create_queue();
    if (queue == NULL) return -1;

    printf("ť ���� �Ϸ�, �ʱ� ũ��: %d\n", get_size(queue));

    // ���� �׽�Ʈ
    printf("\n--- ���� �׽�Ʈ ---\n");
    for (int i = 1; i <= 5; i++) {
        enqueue(queue, i * 10);
        printf("%d ���� �� ũ��: %d\n", i * 10, get_size(queue));
    }
    print_queue(queue);

    // ���� �׽�Ʈ
    printf("\n--- ���� �׽�Ʈ ---\n");
    for (int i = 0; i < 3; i++) {
        int data = dequeue(queue);
        printf("������ ��: %d, ���� ũ��: %d\n", data, get_size(queue));
    }
    print_queue(queue);

    // �߰� ���� (���� Ư�� �׽�Ʈ)
    printf("\n--- ���� ť Ư�� �׽�Ʈ ---\n");
    enqueue(queue, 100);
    enqueue(queue, 200);
    print_queue(queue);

    free_queue(queue);
    printf("\n�޸� ���� �Ϸ�\n");

    return 0;
}