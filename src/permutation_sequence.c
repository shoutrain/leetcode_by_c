/*
 * permutation_sequence.c
 *
 *  Created on: Dec 24, 2015
 *      Author: rafael
 */

#include "permutation_sequence.h"

char *getPermutation(int n, int k) {
	int i;
	int m = n - 1;
	int *sums = (int *) malloc(m * sizeof(int));
	int *nums = (int *) malloc(n * sizeof(int));

	for (i = 0; i < m; i++) {
		if (0 == i) {
			sums[i] = i + 1;
		} else {
			sums[i] = sums[i - 1] * (i + 1);
		}

		nums[i] = i + 1;
	}

	nums[n - 1] = n;

	int *mods = (int *) malloc(m * sizeof(int));
	char *locs = (char *) malloc(n * sizeof(char));

	for (i = 0; i < n; i++) {
		int j = m - i - 1;

		if (0 == i) {
			mods[i] = k % sums[j];
			locs[i] = k / sums[j];
		} else {
			if (i == m) {
				locs[i] = mods[i - 1];
			} else {
				mods[i] = k % sums[j];
				locs[i] = mods[i - 1] / sums[j];
			}
		}

		j = 0;
		int l = 0;

		while (l < locs[i]) {
			if (nums[j++] != 0) {
				l++;
			}
		}

		locs[i] = nums[j] + 48;
		nums[j] = 0;
	}

	return locs;
}

#define N 5
#define K 10

static void _run() {
	printf("The %dth of ermutation of %d is %s\n", K, N, getPermutation(N, K));
}

void permutation_sequence() {
	_run();
}
