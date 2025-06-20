#include "linked_list.h"

LinkedList* create_list(void) {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if (list == NULL) {
        printf("메모리 할당 실패\n");
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

int insert_front(LinkedList* list, int data) {
    if (list == NULL) return -1;

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("메모리 할당 실패\n");
        return -1;
    }

    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    return 0;
}

int insert_back(LinkedList* list, int data) {
    if (list == NULL) return -1;

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("메모리 할당 실패\n");
        return -1;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    }
    else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->size++;
    return 0;
}

int delete_front(LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        printf("리스트가 비어있음\n");
        return -1;
    }

    Node* temp = list->head;
    int data = temp->data;
    list->head = list->head->next;
    free(temp);
    list->size--;
    return data;
}

int delete_back(LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        printf("리스트가 비어있음\n");
        return -1;
    }

    if (list->head->next == NULL) {
        int data = list->head->data;
        free(list->head);
        list->head = NULL;
        list->size--;
        return data;
    }

    Node* current = list->head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    int data = current->next->data;
    free(current->next);
    current->next = NULL;
    list->size--;
    return data;
}

int search(LinkedList* list, int data) {
    if (list == NULL || list->head == NULL) return -1;

    Node* current = list->head;
    int index = 0;

    while (current != NULL) {
        if (current->data == data) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void print_list(LinkedList* list) {
    if (list == NULL || list->head == NULL) {
        printf("리스트가 비어있음\n");
        return;
    }

    printf("리스트 내용: ");
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int is_empty(LinkedList* list) {
    return (list == NULL || list->head == NULL);
}

int get_size(LinkedList* list) {
    return (list == NULL) ? 0 : list->size;
}

void free_list(LinkedList* list) {
    if (list == NULL) return;

    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}