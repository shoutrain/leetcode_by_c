/*
 * permutation_sequence.c
 *
 *  Created on: Dec 24, 2015
 *      Author: rafael
 */

#include "permutation_sequence.h"

char *getPermutation(int n, int k) {
	if (1 == n) {
		char *result = (char *)malloc(2 * sizeof(char));

		result[0] = '1';
		result[1] = '\0';

		return result;
	}

	k--;

	int i;
	int m = n - 1;
	int *sums = (int *) malloc(m * sizeof(int));
	int *nums = (int *) malloc(n * sizeof(int));

	for (i = 1; i <= m; i++) {
		if (1 == i) {
			sums[i - 1] = i;
		} else {
			sums[i - 1] = sums[i - 2] * i;
		}

		nums[i - 1] = i;
	}

	nums[m] = n;

	int *mods = (int *) malloc(m * sizeof(int));
	char *locs = (char *) malloc((n + 1) * sizeof(char));

	locs[n] = '\0';

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

		int l = 0;

		for (j = 0; j < n; j++) {
			if (0 != nums[j]) {
				if (l == locs[i]) {
					break;
				}

				l++;
			}
		}

		assert(j < n);
		locs[i] = nums[j] + 48;
		nums[j] = 0;
	}

	return locs;
}

#define N 1
#define K 1

static void _run() {
	printf("The %dth of ermutation of %d is %s\n", K, N, getPermutation(N, K));
}

void permutation_sequence() {
	_run();
}
