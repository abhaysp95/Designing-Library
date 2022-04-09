#include "glthread.h"

#include <stdio.h>

/** private function to add newnode in first position,
 * new_node is the node to be added and curr_node is generally head node
 */
static void
_glthread_add_next(glthread_node_t *new_node,
		glthread_node_t *curr_node) {
	if (!new_node->right) {  // if new_node is alone, add it in first pos
		new_node->right = curr_node;
		curr_node->left = new_node;  // head's left is NULL, generally
	}

	// if new_node is not alone,
	// add new_node to begining and it's neighbour after the curr_node
	glthread_node_t *neighbour = new_node->right;
	new_node->right = curr_node;
	curr_node->left = new_node;
	curr_node->right = neighbour;
	neighbour->left = curr_node;
}

/** glthread_add adds new glnode into glthread lst at the first position, i.e.,
 * new glnode becomes head of glthread lst */
void
glthread_add(glthread_t *lst, glthread_node_t *glnode) {

	if (!lst) return;

	glnode->left = NULL;
	glnode->right = NULL;

	if (!lst->head) {
		lst->head = glnode;
		return;
	}

	glthread_node_t *head = lst->head;
	_glthread_add_next(glnode, head);
	lst->head = glnode;
}

/**
 * _glthread_remove removes the glnode from within its neighbours
 */
static void
_glthread_remove(glthread_node_t *glnode) {

	if (!glnode->right) {
		if (glnode->left) {
			glnode->left->right = NULL;
			glnode->left = NULL;
			return;
		}
		return;  // glnode neither have left nor right neighbour
	}

	if (!glnode->left) {  // node have his right neighbour but not left
		glnode->right->left = NULL;
		glnode->right = NULL;
		return;
	}

	// node have neighbour on both sides
	glnode->left->right = glnode->right;
	glnode->right->left = glnode->left;
	glnode->left = NULL;
	glnode->right = NULL;
}

/**
 * glthread_remove removes the glnode from the lst
 */
void
glthread_remove(glthread_t *lst, glthread_node_t *glnode) {

	if (!lst) return;

	// if node to remove is the head itself
	if (lst->head == glnode) {
		lst->head = glnode->right;
	}

	_glthread_remove(glnode);
}

void
init_glthread(glthread_t *glthread, uintptr_t offset) {
	glthread->head = NULL;
	glthread->offset = offset;
}
