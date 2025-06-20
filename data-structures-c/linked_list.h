#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

LinkedList* create_list(void);
int insert_front(LinkedList* list, int data);
int insert_back(LinkedList* list, int data);
int delete_front(LinkedList* list);
int delete_back(LinkedList* list);
int search(LinkedList* list, int data);
void print_list(LinkedList* list);
void free_list(LinkedList* list);
int is_empty(LinkedList* list);
int get_size(LinkedList* list);

#endif