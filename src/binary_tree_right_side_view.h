/*
 * binary_tree_right_side_view.h
 *
 *  Created on: Dec 24, 2015
 *      Author: rafael
 */

#ifndef BINARY_TREE_RIGHT_SIDE_VIEW_H_
#define BINARY_TREE_RIGHT_SIDE_VIEW_H_

#include "common.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *rightSideView(struct TreeNode *root, int *returnSize);
void binary_tree_right_side_view();

#endif /* BINARY_TREE_RIGHT_SIDE_VIEW_H_ */
