// queue_array.h
#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

// 원형 큐 구조체
typedef struct Queue {
    int* data;      // 데이터 배열
    int front;      // 큐의 앞
    int rear;       // 큐의 뒤
    int capacity;   // 큐 용량
    int size;       // 현재 큐 크기
} Queue;

// 함수 프로토타입
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

// 큐 생성
Queue* create_queue(void) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("큐 메모리 할당 실패\n");
        return NULL;
    }

    queue->data = (int*)malloc(sizeof(int) * INITIAL_CAPACITY);
    if (queue->data == NULL) {
        printf("배열 메모리 할당 실패\n");
        free(queue);
        return NULL;
    }

    queue->front = 0;
    queue->rear = -1;
    queue->capacity = INITIAL_CAPACITY;
    queue->size = 0;
    return queue;
}

// 데이터 삽입 (enqueue)
int enqueue(Queue* queue, int data) {
    if (queue == NULL) return -1;

    if (is_full(queue)) {
        printf("큐가 가득 참\n");
        return -1;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = data;
    queue->size++;
    return 0;
}

// 데이터 제거 및 반환 (dequeue)
int dequeue(Queue* queue) {
    if (queue == NULL || is_empty(queue)) {
        printf("큐가 비어있음\n");
        return -1;
    }

    int data = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return data;
}

// 큐가 비어있는지 확인
int is_empty(Queue* queue) {
    return (queue == NULL || queue->size == 0);
}

// 큐가 가득 찬지 확인
int is_full(Queue* queue) {
    return (queue != NULL && queue->size == queue->capacity);
}

// 큐 크기 반환
int get_size(Queue* queue) {
    return (queue == NULL) ? 0 : queue->size;
}

// 큐 내용 출력
void print_queue(Queue* queue) {
    if (queue == NULL || is_empty(queue)) {
        printf("큐가 비어있음\n");
        return;
    }

    printf("큐 내용 (front -> rear): ");
    int index = queue->front;
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->data[index]);
        index = (index + 1) % queue->capacity;
    }
    printf("\n");
}

// 메모리 해제
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
    printf("=== 원형 큐 테스트 ===\n\n");

    Queue* queue = create_queue();
    if (queue == NULL) return -1;

    printf("큐 생성 완료, 초기 크기: %d\n", get_size(queue));

    // 삽입 테스트
    printf("\n--- 삽입 테스트 ---\n");
    for (int i = 1; i <= 5; i++) {
        enqueue(queue, i * 10);
        printf("%d 삽입 후 크기: %d\n", i * 10, get_size(queue));
    }
    print_queue(queue);

    // 삭제 테스트
    printf("\n--- 삭제 테스트 ---\n");
    for (int i = 0; i < 3; i++) {
        int data = dequeue(queue);
        printf("삭제된 값: %d, 현재 크기: %d\n", data, get_size(queue));
    }
    print_queue(queue);

    // 추가 삽입 (원형 특성 테스트)
    printf("\n--- 원형 큐 특성 테스트 ---\n");
    enqueue(queue, 100);
    enqueue(queue, 200);
    print_queue(queue);

    free_queue(queue);
    printf("\n메모리 해제 완료\n");

    return 0;
}