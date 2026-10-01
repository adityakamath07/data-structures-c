#ifndef PQ_H
#define PQ_H

typedef struct Node{
    int priority;
    int key;
    struct Node *next;
}node_t;

typedef struct PQ{
    node_t *rear;
    node_t *front;
}pq_t;


void init(pq_t *p);
void enqueue(pq_t *p,int l,int s);
int dequeue(pq_t *p);
int peek(pq_t *p);
int is_empty(pq_t *p);
int is_full(pq_t *p);
void display(pq_t *p);
void deinit(pq_t *p);

#endif
