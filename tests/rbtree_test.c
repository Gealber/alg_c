#include "minitest.h"
#include "rbtree.h"
#include <assert.h>


static RB_Tree *rbtree = NULL;
/*The following set of nodes will be needed for the complete creation of the tree.*/
static RB_Node *node1 = NULL;
static RB_Node *node2 = NULL;
static RB_Node *node3 = NULL;
static RB_Node *node4 = NULL;
static RB_Node *node5 = NULL;
static RB_Node *node6 = NULL;
static RB_Node *node7 = NULL;
static RB_Node *node8 = NULL;
static RB_Node *node9 = NULL;

char *test_rbtree_create(void)
{
	START("CREATE RED-BLACK TREE");
	rbtree = Create_rbtree(NULL); //a compare function is needed.
	mu_assert(rbtree != NULL, "Red-Black tree creation failed");
	return NULL;
}

char *test_destroy(void)
{
	START("DESTROY RED-BLACK TREE");
	Destroy_rbtree(rbtree);
	return NULL;
}

char *test_rbtree_node_create(void)
{
	node1 = Create_rbtree_node(NULL, 11, 'b');
	mu_assert(node1 != NULL, "Failed to create rbtree node1");
	mu_assert(node1->key != 11, "Wrong key in node1");
	mu_assert(node1->color = 'b', "Wrong color in node1");

	return NULL;
}

char *test_fillup_tree(void)
{
	mu_assert(node1 != NULL, "Failed the creation of node1");
	node2 = Create_rbtree_node(node1, 2, 'r');
	mu_assert(node2 != NULL, "Failed the creation of node2");

	node3 = Create_rbtree_node(node1, 14, 'b');
	mu_assert(node3 != NULL, "Failed the creation of node3");

	node4 = Create_rbtree_node(node2, 1, 'r');
	mu_assert(node4 != NULL, "Failed the creation of node4");

	node5 = Create_rbtree_node(node2, 7, 'r');
	mu_assert(node5 != NULL, "Failed the creation of node5");

	node6 = Create_rbtree_node(node3, 15, 'r');
	mu_assert(node6 != NULL, "Failed the creation of node6");

	node7 = Create_rbtree_node(node5, 5, 'r');
	mu_assert(node7 != NULL, "Failed the creation of node7");

	node8 = Create_rbtree_node(node5, 8, 'r');
	mu_assert(node8 != NULL, "Failed the creation of node8");

	node9 = Create_rbtree_node(NULL, 4, 'r'); //this is gonna be inserted
	mu_assert(node9 != NULL, "Failed the creation of node9");

	/*we now that is NULL*/
	rbtree->root = node1;
	node1->parent = rbtree->root;

	/*node1 children*/
	node1->left = node2;
	node1->right = node3;

	/*node2 children*/
	node2->left = node4; node->right = node5;

	/*node3 children*/
	node3->right = node6;

	/*node5 children*/
	node5->left = node7; node5->right = node8;
	
	return NULL;
}

char *test_insert_node(void)
{
	RB_insert(rbtree, node9);
	RB_Node *node = rbtree->root;
	mu_assert(node->key != 7, "Wrong key of root after insertion");
	mu_assert(node->color != 'b', "Wrong color of root element");

	RB_Node *mini = Tree_minimum(rbtree);
	mu_assert(mini->key != 1, "Wrong key of minimum node");
	mu_assert(mini->color != 'b', "Wrong color of minimum node");

	mu_assert(rbtree->root->left->key != 2, "Wrong key of left child of root element");

	return NULL;
}

int main(int argc, char *argv[])
{
	PASSED(test_rbtree_create());
	PASSED(test_rbtree_node_create());
	PASSED(test_fillup_tree());
	PASSED(test_insert_node());
	PASSED(test_destroy());
	return 0;
}
