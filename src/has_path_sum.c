/*
 * has_path_sum.c
 *
 *  Created on: Dec 25, 2015
 *      Author: rafael
 */

#include "has_path_sum.h"

static bool _sum(struct TreeNode *node, int sum, int count) {
	count += node->val;

	if (NULL == node->left && NULL == node->right) {
		if (count == sum) {
			return true;
		} else {
			return false;
		}
	}

	if (NULL != node->left && true == _sum(node->left, sum, count)) {
		return true;
 	}

	if (NULL != node->right && true == _sum(node->right, sum, count)) {
		return true;
	}

	return false;
}

bool hasPathSum(struct TreeNode *root, int sum) {
	if (NULL == root) {
		return false;
	}

	return _sum(root, sum, 0);
}

static void _run() {
	// do nothing
}

void has_path_sum() {
	_run();
}
