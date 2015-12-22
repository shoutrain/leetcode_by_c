/*
 * combinations.h
 *
 *  Created on: Dec 22, 2015
 *      Author: rafael
 */

#ifndef COMBINATIONS_H_
#define COMBINATIONS_H_

#include "common.h"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combine(int n, int k, int **columnSizes, int *returnSize);
void combinations();

#endif /* COMBINATIONS_H_ */
