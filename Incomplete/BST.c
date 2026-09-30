#include <stdio.h>
#include "BST.h"
#include <stdlib.h>

void init(bst_t *ptr_tree){
	ptr_tree->root=NULL;
}

void deinit(bst_t *ptr_tree){
	
