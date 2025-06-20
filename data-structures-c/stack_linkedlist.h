#ifndef _ARRAY_STACK_

#define _ARRAY_STACK_

typedef struct ArrayStack {
	int* items;
	int capacity;
	int top;
} ArrayStack;

ArrayStack* createArrayStack(int size);
int pushArrayStack(ArrayStack* stack, int data);
int popArrayStack(ArrayStack* stack);
int peekArrayStack(ArrayStack* stack);
int isArrayStackEmpty(ArrayStack* stack);
int isArrayStackFull(ArrayStack* stack);
void freeArrayStack(ArrayStack* stack);


#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_
#define TRUE		1
#define FALSE		0	
#endif