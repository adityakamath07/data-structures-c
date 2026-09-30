#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void init_stack(stack_t *s){
	s->top=NULL;
}

void push(stack_t *s,int l){
	node_t *new=malloc(sizeof(node_t));
	if(new==NULL){
		printf("Memory allocation failed");
		return;
	}
	new->key=l;
	new->next=s->top;
	s->top=new;
}

int pop(stack_t *s){
	if(s->top==NULL){
		printf("The stack is empty!!YOu get a zeroooo");
		return 0;
	}
	int l=s->top->key;
	node_t *temp=s->top;
	s->top=s->top->next;
	free(temp);
	return l;
}

int peek(stack_t *s){
	if(s->top==NULL){
		printf("The stack is empty! You get a z0rroooooo");
		return 0;
	}
	return s->top->key;
}

void display(stack_t *s){
	if(s->top==NULL){
		printf("The stack is empty");
		return;
	}
	node_t *temp=s->top;
	while(temp!=NULL){
  		printf("%d ",temp->key);
		temp=temp->next;
	}
}

void deinit_stack(stack_t *s){
	if(s->top==NULL)return;
	node_t *temp=s->top;
	while(temp!=NULL){
		pop(s);
		temp=s->top;
	}
	free(temp);
}



