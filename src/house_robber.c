/*
 * house_robber.c
 *
 *  Created on: Dec 28, 2015
 *      Author: rafael
 */

#include "house_robber.h"

int rob(int *nums, int numsSize) {
	if (NULL == nums || 0 == numsSize) {
		return 0;
	}

	int *money = (int *)malloc(numsSize * sizeof(int));
	int i = 2;

	money[0] = nums[0];
	money[1] = nums[0] > nums[1] ? nums[0] : nums[1];

	for (; i < numsSize; i++) {
		money[i] = nums[i] + money[i - 2];

		if (money[i - 1] > money[i]) {
			money[i] = money[i - 1];
		}
	}

	return money[numsSize - 1] > money[numsSize - 2] ?
			money[numsSize - 1] : money[numsSize - 2];
}

static void _run() {
	int nums[] = {1,3,1,3,100};

	printf("%d\n", rob(nums, 5));
}

void house_robber() {
	_run();
}
