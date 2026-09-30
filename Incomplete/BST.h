#ifndef BST_H
#define BST_H

typedef struct Node{
	int key;
	struct Node *left;
	struct Node *right;
}node_t;

typedef struct Tree{
	node_t *root;
}bst_t;

void init(bst_t *ptr_tree);
void deinit(bst_t *ptr_tree);
void display(bst_t *ptr_tree);
void insert(bst_t *ptr_tree, int key);
int number_of_nodes(bst_t *ptr_tree);
int number_of_leaves(bst_t *ptr_tree);

#endif
