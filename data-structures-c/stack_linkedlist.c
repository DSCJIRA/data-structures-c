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
			printf("오류, 메모리 할당, createArrayStack()\n");
			return NULL;
		}
	}
	else {
		printf("오류, 스택의 크기는 0이상이어야 합니다.\n");
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
			stack->top++;//top을 capacity로 함.
			stack->items[stack->top] = data;//top을 capacity로 함.
			ret = TRUE;
		}
		else {
			printf("오류, 스택이 가득 찼습니다, pushAS()\n");
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
	int data = stack->items[stack->top]; // 최상단 데이터 저장
	stack->top--;                        // 최상단 인덱스 감소
	return data;
}



int peekArrayStack(ArrayStack* stack) {
	if (stack != NULL && stack->items != NULL) {//&&로 stak이 널인 경우 바로 탈출해야 하는데 or인 경우 item 연산이 불가능하기 때문.
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