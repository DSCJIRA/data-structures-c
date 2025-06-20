#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_linkedlist.h"

ArrayStack* createArrayStack(int size) {
	ArrayStack* pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
	/*if (size <= 0) {
		return NULL;
	}

	ArrayStack* pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (pReturn == NULL) {
		return NULL;
	}

	int* stack = (int*)malloc(size * sizeof(int));
	if (stack == NULL) {
		free(pReturn);
		return NULL;
	}

	pReturn->items = stack;
	pReturn->capacity = size;
	pReturn->top = -1;

	*/

	if (size > 0) {
		if (pReturn != NULL) {
			pReturn->capacity = size;
			pReturn->top = -1;
		}
		else {
			printf("����, �޸� �Ҵ�, createArrayStack()\n");
			return NULL;
		}
	}
	else {
		printf("����, ������ ũ��� 0�̻��̾�� �մϴ�.\n");
		return NULL;
	}
	pReturn->items = (int*)malloc(size * sizeof(int));
	return pReturn;
}

int pushArrayStack(ArrayStack* stack, int data) {
	int ret = FALSE;
	if (stack != NULL) {
		if (isArrayStackFull(stack) == FALSE)
		{
			stack->top++;//top�� capacity�� ��.
			stack->items[stack->top] = data;//top�� capacity�� ��.
			ret = TRUE;
		}
		else {
			printf("����, ������ ���� á���ϴ�, pushAS()\n");
		}
	}
	return ret;
}

int popArrayStack(ArrayStack* stack) {
	/*if (stack->items != NULL)
	{
		free(stack->items);
	}
	free(stack);
	*/
	if (stack == NULL || isArrayStackEmpty(stack)) {
		return -1;
	}
	int data = stack->items[stack->top]; // �ֻ�� ������ ����
	stack->top--;                        // �ֻ�� �ε��� ����
	return data;
}



int peekArrayStack(ArrayStack* stack) {
	if (stack != NULL && stack->items != NULL) {//&&�� stak�� ���� ��� �ٷ� Ż���ؾ� �ϴµ� or�� ��� item ������ �Ұ����ϱ� ����.
		return stack->items[stack->top];
	}
	else {
		return INT_MIN;
	}
}

int isArrayStackEmpty(ArrayStack* stack) {
	return (stack->top == -1 || stack == NULL);
}
int isArrayStackFull(ArrayStack* stack) {
	return (stack->top == stack->capacity - 1);
}

void freeArrayStack(ArrayStack* stack) {
	int ret = FALSE;
	if (stack != NULL) {
		free(stack->items);
		free(stack);
		/*if (stack->capacity == stack->top) {
			ret = TRUE;
		}
		*/
	}
	return ret;
}