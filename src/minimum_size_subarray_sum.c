/*
 * minimum_size_subarray_sum.c
 *
 *  Created on: Dec 23, 2015
 *      Author: rafael
 */

#include "minimum_size_subarray_sum.h"

// different problem doesn't meet subarray
int minInArrayLen(int s, int *nums, int numsSize) {
	int i, j;
	int total = 0;

	for (i = 0; i < numsSize; i++) {
		for (j = i + 1; j < numsSize; j++) {
			if (nums[i] < nums[j]) {
				nums[i] ^= nums[j];
				nums[j] ^= nums[i];
				nums[i] ^= nums[j];
			}
		}

		total += nums[i];

		if (total >= s) {
			return i + 1;
		}
	}

	return 0;
}

int minSubArrayLen(int s, int *nums, int numsSize) {
	int i = 0;
	int j = 0;
	int min = -1;
	int sum = 0;

	while (j < numsSize) {
		while (sum < s && j < numsSize) {
			sum += nums[j++];
		}

		if (sum >= s) {
			while (sum >= s && i < j) {
				sum -= nums[i++];
			}

			if (-1 == min || min > j - i + 1) {
				min = j - i + 1;
			}
		}
	}

	return -1 == min ? 0 : min;
}

#define NUMS_LENGTH 14
#define COMPARE_NUM 80

static void _run() {
	int nums[] = { 10, 5, 13, 4, 8, 4, 5, 11, 14, 9, 16, 10, 20, 8 };
	int i;

	printf("The array is: [ ");

	for (i = 0; i < NUMS_LENGTH; i++) {
		printf("%d ", nums[i]);
	}

	printf("]\n");

	int len = minSubArrayLen(COMPARE_NUM, nums, NUMS_LENGTH);

	printf("The min subarray len is: %d\n", len);
}

void minimum_size_subarray_sum() {
	_run();
}
