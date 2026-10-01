#include <stdio.h>
#include <stdlib.h>
#include "Priority_Queue.h"

void init(pq_t *q){
	q->rear=q->front=NULL;
}

void enqueue(pq_t *q,int a,int p){
	if(q==NULL)return;
	node_t *new=malloc(sizeof(node_t));
	if(new==NULL){
		printf("Memory Allocation Failed!");
		return;
	}
	new->key=a;
    new->priority=p;
	new->next=NULL;
	if(q->front==NULL){
		q->front=q->rear=new;
		return;
	}
    if(new->priority<q->front->priority){
        new->next=q->front;
        q->front=new;
        return;
    }
    node_t *temp=q->front->next;
    node_t *prev=q->front;
    while(temp!=NULL){
        if(new->priority<temp->priority){
            new->next=temp;
            prev->next=new;
            return;
        }
        prev=prev->next;
        temp=temp->next;
    }
	q->rear->next=new;
	q->rear=new;
}

int dequeue(pq_t *q){
	if(q==NULL||q->front==NULL){
		printf("Enter something first. You get a 0 for this behaviour");
		return 0;
	}
	node_t *temp=q->front;
	int ans=temp->key;
	q->front=q->front->next;
	free(temp);
	if(q->front == NULL)
    		q->rear = NULL;
	return ans;
}

int peek(pq_t *q){
	if(q==NULL||q->front==NULL){
		printf("There is no element. I give you a zero.");
		return 0;
	}
	return q->front->key;
}

int is_empty(pq_t *q){
	return q==NULL||q->front==NULL;
}

int is_full(pq_t *q){
	node_t *new=malloc(sizeof(node_t));
	if(new==NULL){
		return 1;
	}
	free(new);
	return 0;
}

void display(pq_t *q){
	if(q==NULL)return;
	node_t *temp=q->front;
	while(temp!=NULL){
		printf("%d ",temp->key);
        printf("%d ",temp->priority);
		temp=temp->next;
	}
}

void deinit(pq_t *q){
	node_t *temp=q->front;
	while(q->front!=NULL){
		temp=q->front;
		q->front=q->front->next;
		free(temp);
	}
	q->rear=NULL;
}



