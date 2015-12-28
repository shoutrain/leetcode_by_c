/*
 * same_tree.h
 *
 *  Created on: Dec 28, 2015
 *      Author: rafael
 */

#ifndef SAME_TREE_H_
#define SAME_TREE_H_

#include "common.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode *p, struct TreeNode *q);
void same_tree();

#endif /* SAME_TREE_H_ */
