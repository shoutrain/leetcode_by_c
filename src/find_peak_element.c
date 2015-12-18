/*
 * find_peak_element.c
 *
 *  Created on: Dec 18, 2015
 *      Author: rafael
 */

#include "find_peak_element.h"

int findPeakElement(int *nums, int numsSize) {
	int left = 0;
	int right = numsSize - 1;

	while (left <= right) {
		if (left == right) {
			return left;
		}

		int mid = (left + right) / 2;

		if (nums[mid] < nums[mid + 1]) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	return -1;
}

#define NUM 4

static void _run() {
	int array[4] = {1, 2, 3, 1};
	int peakIndex = findPeakElement(array, NUM);

	printf("peak index: %d\n", peakIndex);
}

void find_peak_element() {
	_run();
}
