#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *before;
}Node;
typedef struct Stack
{
	Node *front;
	Node *rear;
	int count;
}Stack;
void initStack(Stack *stack)
{
	stack->front = stack->rear = NULL;
	stack->count = 0;
}

int isEmpty(Stack *stack)
{
	return stack->count == 0;
}

void enstack(Stack *stack, int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->before = NULL;

	if (isEmpty(stack)){
		stack->front = newNode;
	}
	else{
		newNode->before = stack->rear;
	}
	stack->rear = newNode;
	stack->count++;
} 
int destack(Stack *stack)
{
	int data;
	Node *ptr;
	if (isEmpty(stack)){
		printf("Error : Stack is empty!\n");
		return 0;
	}
	ptr = stack->rear;
	data = ptr->data;
	stack->rear = ptr->before;
	free(ptr);
	stack->count--;
	return data;
}

int main(void)
{
	int i;
	Stack stack;
	initStack(&stack);
	enstack(&stack,10);
	enstack(&stack,20);
	enstack(&stack,30);
	printf("%d\n",destack(&stack));
	printf("%d\n",destack(&stack));
	printf("%d\n",destack(&stack));
	return 0;
}
