#include <stdio.h>
#include <stdlib.h>

typedef int (*RB_Tree_compare)(void *a, void *b);

typedef struct RB_Node {
	char color;
	void *key;
	RB_Node *left;
	RB_Node *right;
	RB_Node *parent;
} RB_Node;

typedef struct RB_Tree {
	int count;
	RB_Tree_compare cmp;
	RB_Node *root;
	NULL sentinel;
} RB_Tree;

RB_Tree *Create_rbtree(RB_Tree_compare cmp);
RB_Node *Create_rbtree_node(RB_Node *parent, void *key, char color);
void Destroy_rbtree(RB_Tree *T);
int Destroy_rbtree_node(RB_Node *node);
void Left_rotate(RB_Tree *T, RB_Node *x);
void Right_rotate(RB_Tree *T, RB_Node *y);
void RB_insert(RB_Tree *T, RB_Node *z);
void RB_insert_fixup(RB_Tree *T, RB_Node *z);
void RB_Transplant(RB_Tree *T, RB_Node *u, RB_Node v);

