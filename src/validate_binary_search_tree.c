/*
 * validate_binary_search_tree.c
 *
 *  Created on: Dec 26, 2015
 *      Author: rafael
 */

#include "validate_binary_search_tree.h"

static bool _isValid(struct TreeNode *root, struct TreeNode *node) {
	if (root == node) {
		return true;
	}

	if (node->val < root->val) {
		if (NULL == root->left) {
			return false;
		}

		return _isValid(root->left, node);
	} else if (node->val > root->val) {
		if (NULL == root->right) {
			return false;
		}

		return _isValid(root->right, node);
	} else {
		return false;
	}
}

static bool _traversal(struct TreeNode *root, struct TreeNode *node) {
	if (false == _isValid(root, node)) {
		return false;
	}

 	if (NULL != node->left) {
		if (false == _traversal(root, node->left)) {
			return false;
		}
	}

	if (NULL != node->right) {
		return _traversal(root, node->right);
	}

	return true;
}

bool isValidBST(struct TreeNode *root) {
	if (NULL == root) {
		return true;
	}

	return _traversal(root, root);
}

static void _run() {
	// do nothing
}

void validate_binary_search_tree() {
	_run();
}
