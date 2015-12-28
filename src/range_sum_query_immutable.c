/*
 * range_sum_query_immutable.c
 *
 *  Created on: Dec 28, 2015
 *      Author: rafael
 */

#include "range_sum_query_immutable.h"

struct NumArray *NumArrayCreate(int *nums, int numsSize) {
	struct NumArray *array =
			(struct NumArray *)malloc(numsSize * sizeof(struct NumArray));
	int i = 1;

	array[0].preTotal = 0;
	array[0].value = nums[0];

	for (; i < numsSize; i++) {
		array[i].preTotal = array[i - 1].preTotal + nums[i - 1];
		array[i].value = nums[i];
	}

	return array;
}

int sumRange(struct NumArray *numArray, int i, int j) {
	return numArray[j].preTotal + numArray[j].value - numArray[i].preTotal;
}

/**
 * Deallocates memory previously allocated for the data structure.
 */
void NumArrayFree(struct NumArray *numArray) {
	free(numArray);
}

// Your NumArray object will be instantiated and called as such:
// struct NumArray* numArray = NumArrayCreate(nums, numsSize);
// sumRange(numArray, 0, 1);
// sumRange(numArray, 1, 2);
// NumArrayFree(numArray);

static void _run() {
	int nums[] = {1, 3, -1, 0, 9, -8};
	struct NumArray *numArray = NumArrayCreate(nums, 6);

	printf("%d from %d - %d\n", sumRange(numArray, 0, 1), 0, 1);
	printf("%d from %d - %d\n", sumRange(numArray, 1, 2), 1, 2);

	NumArrayFree(numArray);
}

void range_sum_query_immutable() {
	_run();
}
