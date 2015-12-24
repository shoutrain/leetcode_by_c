/*
 * sum_root_to_leaf_numbers.h
 *
 *  Created on: Dec 24, 2015
 *      Author: rafael
 */

#ifndef SUM_ROOT_TO_LEAF_NUMBERS_H_
#define SUM_ROOT_TO_LEAF_NUMBERS_H_

#include "common.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumNumbers(struct TreeNode *root);
void sum_root_to_leaf_numbers();

#endif /* SUM_ROOT_TO_LEAF_NUMBERS_H_ */
