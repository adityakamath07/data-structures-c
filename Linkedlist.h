#ifndef LL_H
#define LL_H

typedef struct node{
	double key;
	struct node *next;
}node_t;

void init_list(node_t **head);
node_t *createNode(double data);
node_t *insert(node_t *head,double data,int pos);
double del(node_t **head,char *ch);
node_t *order(node_t *head,char *ch);
void display(node_t *head);
void deinit_list(node_t *head);

#endif
