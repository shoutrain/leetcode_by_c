/*
 * burst_balloons.c
 *
 *  Created on: Dec 28, 2015
 *      Author: rafael
 */

#include "burst_balloons.h"

int burst(int **cals, int *nums, int l, int r) {
	if (l + 1 == r) {
		return 0;
	}

	if (cals[l][r] > 0) {
		return cals[l][r];
	}

	int m;

	for (m = l + 1; m < r; m++) {
		int temp = nums[l] * nums[m] * nums[r] + burst(cals, nums, l, m) +
				burst(cals, nums, m, r);

		if (cals[l][r] < temp) {
			cals[l][r] = temp;
		}
	}

	return cals[l][r];
}

int maxCoins(int *nums, int numsSize) {
	int *numbers = (int *) malloc((numsSize + 2) * sizeof(int));
	int n = 1;

	for (; n <= numsSize; n++) {
		numbers[n] = nums[n - 1];
	}

	numbers[0] = numbers[n++] = 1;

	int **cals= (int **) malloc(n * sizeof(int *));
	int i = 0;

	for (; i < n; i++) {
		cals[i] = (int *)malloc(n * sizeof(int));
		memset(cals[i], 0, n * sizeof(int));
	}

	int result = burst(cals, numbers, 0, n - 1);

	for (i = 0; i < n; i++) {
		free(cals[i]);
	}

	free(cals);
	free(numbers);

	return result;
}

static void _run() {
	int nums[] = {3, 1, 5};

	printf("%d\n", maxCoins(nums, 3));
}

void burst_balloons() {
	_run();
}
