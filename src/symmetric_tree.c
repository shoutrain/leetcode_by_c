/*
 * symmetric_tree.c
 *
 *  Created on: Dec 26, 2015
 *      Author: rafael
 */

#include "symmetric_tree.h"

static bool _isMirror(struct TreeNode *real, struct TreeNode *mirror) {
	if (real->val != mirror->val) {
		return false;
	}

	if (NULL != real->left && NULL != mirror->right) {
		if (false == _isMirror(real->left, mirror->right)) {
			return false;
		}
	} else if (NULL != real->left || NULL != mirror->right) {
		return false;
	}

	if (NULL != real->right && NULL != mirror->left) {
		return _isMirror(real->right, mirror->left);
	} else if (NULL != real->right || NULL != mirror->left) {
		return false;
	}

	return true;
}

bool isSymmetric(struct TreeNode *root) {
	if (NULL == root) {
		return true;
	}

	if (NULL == root->left && NULL == root->right) {
		return true;
	}

	if (NULL != root->left && NULL != root->right) {
		return _isMirror(root->left, root->right);
	}

	return false;
}

static void _run() {
	// do nothing
}

void symmetric_tree() {
	_run();
}
