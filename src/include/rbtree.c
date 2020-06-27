#include "rbtree.h"

/*This file contains an implementation of a Red Black Tree.
 * Red Black Tree properties:
 * 1. Every node is either red or black.
 * 2. The root is black.
 * 3. Every leaf (NULL) is black.
 * 4. If a node is red, then both its children are black.
 * 5. For each node, all simple path from the node to descendent leaves contain
 * 	the same number of black nodes.
 * This properties is from The Book.*/

/*Create_rbtree: create a Red Black tree and returns it.*/
RB_Tree *Create_rbtree(RB_Tree_compare cmp)
{
	RB_Tree *T = calloc(1, sizeof(RB_Tree));
	check_mem(T);
	
	if (!cmp) {
		fprintf("You should provide a compare function\n");
		goto error;
	}
	
	T->cmp = cmp;
error:
	if (T) 
		Destroy_rbtree(T);
	return NULL;
}

/*Create_rbtree_node: create a node of a Red-Black Tree and returns it.*/
RB_Node *Create_rbtree_node(RB_Node *parent, void *key, char color)
{
	RB_Node *node = calloc(1, sizeof(RB_Node));
	check_mem(node);
	
	node->color = color;
	node->key = key;
	node->parent = parent;
	return node;	
error:
	if (node) 
		Destroy_rbtree_node(node);
	return NULL
}

/*Destroy_rbtree_node: free up the memory hold by the given node.*/
int Destroy_rbtree_node(RB_Node *node)
{
	free(node);
	return 0;
}

/*Destroy_rbtree: free up the memory reserved by the given tree.*/
void Destroy_rbtree(RB_Tree *T)
{
	return;
}

/*Left_rotate: update the node according to a left rotation.*/
void Left_rotate(RB_Tree *T, RB_Node *x)
{
	RB_Node *y = x->right;
	x->right = y->left;
	if (y->left != T->sentinel)
		y->left->parent = x;
	
	y->parent = x->parent;
	if (x->parent == T->sentinel)
		T->root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else 
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

/*Rigth_rotate: update the node according to a right rotation.*/
void Right_rotate(RB_Tree *T, RB_Node *y)
{
	RB_Node *x = y->left;
	y->left = x->right;
	if (x->right != T->sentinel)
		x->right->parent = y;
	
	x->parent = y->parent;
	if (y->parent == T->sentinel)
		T->root = x;
	else if (y == y->parent->right)
		y->parent->right = x;
	else 
		y->parent->left = x;

	x->right = y;
	y->parent = x;
}

/*RB_insert: insert the given node into the RB_Tree and update the color.*/
void RB_insert(RB_Tree *T, RB_Node *z)
{
	y = T->sentinel;
	x = T->root;
	while (x != T->sentinel) {
		y = x;
		if (T->compare(z->key, x->key) == -1)
			x = x->left;
		else
			x = x->right;
	}

	z->parent = y;
	if (y == T->sentinel)
		T->root = z;
	else if (T->compare(z->key, y->key) == -1)
		y->left = z;
	else
		y->right = z;
	z->left = T->sentinel;
	z->right = T->sentinel;
	z->color = 'r';
	RB_insert_fixup(T, z);
}

/*choose_side:to avoid repetition nothing magic. 0 is left and
 * anyother number is right.*/
void choose_side(RB_Node *z, int side)
{
	if (side == 0)
		RB_Node *y = z->parent->parent->left;
	else
		RB_Node *y = z->parent->parent->right;
	RB_Node *nephew_side = side == 0? z->parent->left: z->parent->right;

	if (y->color == 'r') {
		z->parent->color = 'b';
		y->color = 'b';
		z->parent->parent->color = 'r';
		z = z->parent->parent;
	} else { 
		if (z == nephew_side) {
			z = z->parent;
			Left_rotate(T, z);
		}
		z->parent->color = 'b';
		z->parent->parent->color = 'r';
		Right_rotate(T, z->parent->parent);
	}
}	

/*RB_insert_fixup: fix the tree in a way that hold the properties of a RB_Tree->
 * This is the most magic method->*/
void RB_insert_fixup(RB_Tree *T, RB_Node *z)
{
	while (z->parent->color == 'r') {
		if (z->parent == z->parent->parent->left)
			choose_side(z, 0);
		else 
			choose_side(z, 1);
	}
	T->root->color = 'b';
}

/*RB_Transplant: reorganize the subtrees of the node to be deleted appropiately.
 * This method is meant to be used by RB_Tree_delete.*/
void RB_Transplant(RB_Tree *T, RB_Node *u, RB_Node *v)
{
	if (u->parent == T->sentinel) 
		T->root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

/*RB_Delete: delete a given node from the Red-Black Tree.*/
