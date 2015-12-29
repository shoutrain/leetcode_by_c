/*
 * remove_duplicates_from_sorted_array.c
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#include "remove_duplicates_from_sorted_array.h"

int removeDuplicates(int *nums, int numsSize) {
	if (0 == numsSize) {
		return 0;
	}

	int i = 1;
	int j = 0;

	for (; i < numsSize; i++) {
		if (nums[i] != nums[j]) {
			j++;
			nums[j] = nums[i];
		}
	}

	return j + 1;
}

static void _run() {
	int nums[] = {1, 1, 3, 4, 5, 5, 7, 7, 8};

	printf("%d\n", removeDuplicates(nums, 9));
}

void remove_duplicates_from_sorted_array() {
	_run();
}

