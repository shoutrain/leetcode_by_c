/*
 * same_tree.c
 *
 *  Created on: Dec 28, 2015
 *      Author: rafael
 */

#include "same_tree.h"

bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
	if (NULL == p && NULL == q) {
		return true;
	}

	if (NULL == p || NULL == q) {
		return false;
	}

	if (p->val != q->val) {
		return false;
	}

	if (false == isSameTree(p->left, q->left)) {
		return false;
	}

	return isSameTree(p->right, q->right);
}

static void _run() {
	// do nothing
}

void same_tree() {
	_run();
}
