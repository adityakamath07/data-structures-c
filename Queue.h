#ifndef Q_H
#define Q_H

typedef struct Node{
	double key;
	struct Node *next;
}node_t;

typedef struct Queue{
	node_t *front;
	node_t *rear;
}queue_t;

void init(queue_t *p);
void enqueue(queue_t *p,int l);
int dequeue(queue_t *p);
int peek(queue_t *p);
int is_empty(queue_t *p);
int is_full(queue_t *p);
void display(queue_t *p);
void deinit(queue_t *p);

#endif
