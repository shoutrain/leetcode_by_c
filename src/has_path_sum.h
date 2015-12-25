/*
 * has_path_sum.h
 *
 *  Created on: Dec 25, 2015
 *      Author: rafael
 */

#ifndef HAS_PATH_SUM_H_
#define HAS_PATH_SUM_H_

#include "common.h"

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum);
void has_path_sum();

#endif /* HAS_PATH_SUM_H_ */
