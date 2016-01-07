/*
 * unique_binary_search_tree.c
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#include "unique_binary_search_tree.h"

int numTrees(int n) {
	if (1 >= n) {
		return 1;
	}

	int *nums = (int *)malloc((n + 1) * sizeof(int));
	int i, j;

	nums[0] = 1;
	nums[1] = 1;

	for (i = 2; i <= n; i++) {
		nums[i] = 0;

		for (j = 1; j <= i; j++) {
			nums[i] += nums[i - j] * nums[j - 1];
		}
	}

	int m = nums[n];

	free(nums);

	return m;
}

#define N 3

static void _run() {
	printf("%d's result: %d\n", N, numTrees(N));
}

void unique_binary_search_tree() {
	_run();
}
