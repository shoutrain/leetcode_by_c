/*
 * binary_tree_right_side_view.c
 *
 *  Created on: Dec 24, 2015
 *      Author: rafael
 */

#include "binary_tree_right_side_view.h"

#define STEP 64

static int *_reNewArray(int *array, int *size) {
	int *newArray = (int *) malloc((*size + STEP) * sizeof(int));
	int i = 0;

	for (; i < *size; i++) {
		newArray[i] = array[i];
	}

	free(array);
	*size += STEP;

	return newArray;
}

static void _traversal(struct TreeNode *node, int *array, int arraySize,
		int deep, int *returnSize) {
	if (deep > *returnSize) {
		(*returnSize)++;

		if (*returnSize >= arraySize) {
			array = _reNewArray(array, &arraySize);
		}

		array[*returnSize - 1] = node->val;
	}

	if (NULL != node->right) {
		_traversal(node->right, array, arraySize, ++deep, returnSize);
		deep--;
	}

	if (NULL != node->left) {
		_traversal(node->left, array, arraySize, ++deep, returnSize);
		deep--;
	}
}

int *rightSideView(struct TreeNode *root, int *returnSize) {
	if (NULL == root) {
		*returnSize = 0;

		return NULL;
	}

	int *array = (int *) malloc(STEP * sizeof(int));

	*returnSize = 0;
	_traversal(root, array, STEP, 1, returnSize);

	return array;
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

	int returnSize = 0;
	int *array = rightSideView(nodes, &returnSize);
	int i = 0;

	printf("[ ");

	for (; i < returnSize; i++) {
		printf("%d ", array[i]);
	}

	printf("]\n");
}

void binary_tree_right_side_view() {
	_run();
}

