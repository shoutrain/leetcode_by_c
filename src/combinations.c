/*
 * combinations.c
 *
 *  Created on: Dec 22, 2015
 *      Author: rafael
 */

#include "combinations.h"

static int _calCombineNum(int n, int r) {
	int i;
	int combineNNSubR = 1;
	int combineR = 1;

	for (i = n; i > n - r; i--) {
		combineNNSubR *= i;
	}

	for (i = r; i > 1; i--) {
		combineR *= i;
	}

	return combineNNSubR / combineR;
}

static int _combine(int start, int end, int length, int yOffset, int xOffset,
		int **results) {
	if (1 == length) {
		int count = 0;
		int i;

		for (i = start; i <= end; i++) {
			results[yOffset + count][xOffset] = i;
			count++;
		}

		return count;
	} else {
		int total = 0;
		int i, j;

		for (i = start; i <= end - length + 1; i++) {
			int count = _combine(i + 1, end, length - 1, yOffset + total,
					xOffset + 1, results);

			for (j = 0; j < count; j++) {
				results[yOffset + total + j][xOffset] = i;
			}

			total += count;
		}

		return total;
	}
}

int **combine(int n, int k, int **columnSizes, int *returnSize) {
	int i;

	*returnSize = _calCombineNum(n, k);
	*columnSizes = (int *) malloc(*returnSize * sizeof(int));

	int **results = (int **) malloc(*returnSize * sizeof(int *));

	for (i = 0; i < *returnSize; i++) {
		columnSizes[0][i] = k;
		results[i] = (int *) malloc(k * sizeof(int));
	}

	int count = _combine(1, n, k, 0, 0, results);
	assert(count == *returnSize);

	return results;
}

#define N 1
#define K 1

static void _run() {
	printf("n = %d, k = %d\n", N, K);

	int *columnSizes = NULL;
	int returnSize = 0;
	int **results = combine(N, K, &columnSizes, &returnSize);
	int i, j;

	printf("[\n");

	for (i = 0; i < returnSize; i++) {
		printf("  [ ");

		for (j = 0; j < columnSizes[i]; j++) {
			printf("%d ", results[i][j]);
		}

		printf("]\n");
	}

	printf("]\n");
}

void combinations() {
	_run();
}

