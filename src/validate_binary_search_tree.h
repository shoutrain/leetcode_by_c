/*
 * validate_binary_search_tree.h
 *
 *  Created on: Dec 26, 2015
 *      Author: rafael
 */

#ifndef VALIDATE_BINARY_SEARCH_TREE_H_
#define VALIDATE_BINARY_SEARCH_TREE_H_

#include "common.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isValidBST(struct TreeNode *root);
void validate_binary_search_tree();

#endif /* VALIDATE_BINARY_SEARCH_TREE_H_ */
