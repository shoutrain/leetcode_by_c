/*
 * sum_root_to_leaf_numbers.c
 *
 *  Created on: Dec 24, 2015
 *      Author: rafael
 */

#include "sum_root_to_leaf_numbers.h"

static int _sum(struct TreeNode *node, int number) {
	int total = 0;

	if (NULL != node->left) {
		total += _sum(node->left, number * 10 + node->left->val);
	}

	if (NULL != node->right) {
		total += _sum(node->right, number * 10 + node->right->val);
	}

	return 0 == total ? number : total;
}

int sumNumbers(struct TreeNode *root) {
	if (NULL == root) {
		return 0;
	}

	return _sum(root, root->val);
}

#define NODE_NUM 3

static void _run() {
	struct TreeNode *nodes =
			(struct TreeNode *) malloc(NODE_NUM * sizeof(struct TreeNode *));

	nodes[0].val = 1;
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];

	nodes[1].val = 2;
	nodes[1].left = NULL;
	nodes[1].right = NULL;

	nodes[2].val = 3;
	nodes[2].left = NULL;
	nodes[2].right = NULL;

	printf("%d\n", sumNumbers(nodes));
}

void sum_root_to_leaf_numbers() {
	_run();
}
