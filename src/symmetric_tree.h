/*
 * symmetric_tree.h
 *
 *  Created on: Dec 26, 2015
 *      Author: rafael
 */

#ifndef SYMMETRIC_TREE_H_
#define SYMMETRIC_TREE_H_

#include "common.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSymmetric(struct TreeNode *root);
void symmetric_tree();

#endif /* SYMMETRIC_TREE_H_ */
