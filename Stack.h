#ifndef STACK_H
#define STACK_H

typedef struct Node{
	double key;
	struct Node *next;
}node_t;

typedef struct Stack{
	node_t *top;
}stack_t;

void init_stack(stack_t *s);
void push(stack_t *s,int l);
int pop(stack_t *s);
int peek(stack_t *s);
void display(stack_t *s);
void deinit_stack(stack_t *s);

#endif
