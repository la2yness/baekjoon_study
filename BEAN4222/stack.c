#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct element {
	int number;
	char name[10];
}element;
typedef struct StackType{
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s){
	s->top = -1;
}

int is_empty(StackType* s){
	return (s->top == -1);
}

int is_full(StackType* s){
	return (s->top == (MAX_STACK_SIZE -1));
}

void push(StackType* s, element item){
	if (is_full(s)) {
		fprintf(stderr,"스택 포화\n");
		return;
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s){
	if (is_empty(s)){
		fprintf(stderr,"스택 공백\n");
	}
	return s->data[(s->top)--];
}

element peek(StackType* s){
	if (is_empty(s)){
		fprintf(stderr,"스택 공백\n");
	}
	return s->data[s->top];
}


int main(){
	element tmp;
	
	StackType s1;
	init_stack(&s1);
	scanf("%d",&tmp.number);
	push(&s1,tmp);
	tmp.number = 10;
	push(&s1,tmp);
	printf("%d\n",peek(&s1).number);
	printf("%d\n",pop(&s1).number);
	printf("%d\n",pop(&s1).number);
	printf("%d\n",pop(&s1).number);
	
	

	return 0;
}
