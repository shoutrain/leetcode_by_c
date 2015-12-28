/*
 * range_sum_query_immutable.h
 *
 *  Created on: Dec 28, 2015
 *      Author: rafael
 */

#ifndef RANGE_SUM_QUERY_IMMUTABLE_H_
#define RANGE_SUM_QUERY_IMMUTABLE_H_

#include "common.h"

struct NumArray {
	int preTotal;
	int value;
};

/**
 * Initialize your data structure here.
 */
struct NumArray *NumArrayCreate(int *nums, int numsSize);

int sumRange(struct NumArray *numArray, int i, int j);

/**
 * Deallocates memory previously allocated for the data structure.
 */
void NumArrayFree(struct NumArray *numArray);

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);

void range_sum_query_immutable();


#endif /* RANGE_SUM_QUERY_IMMUTABLE_H_ */
