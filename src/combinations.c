/*
 * combinations.c
 *
 *  Created on: Dec 22, 2015
 *      Author: rafael
 */

#include "combinations.h"

int _calCombineNum(int n, int r) {
	int i;
	int combineN = 1;
	int combineR = 1;
	int combineNSubR = 1;

	for (i = n; i > 1; i--) {
		combineN *= i;
	}

	for (i = r; i > 1; i--) {
		combineR *= i;
	}

	for (i = n - r; i > 1; i--) {
		combineNSubR *= i;
	}

	return combineN / (combineR * combineNSubR);
}

int _combine(int start, int end, int length, int yOffset, int xOffset,
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
	columnSizes = (int **) malloc(*returnSize * sizeof(int *));

	int **results = (int **) malloc(*returnSize * sizeof(int *));

	for (i = 0; i < *returnSize; i++) {
		columnSizes[i] = (int *) malloc(sizeof(int));
		columnSizes[i][0] = k;
		results[i] = (int *) malloc(k * sizeof(int));
	}

	int count = _combine(1, n, k, 0, 0, results);
	assert(count == *returnSize);

	return results;
}

#define N 5
#define K 2

static void _run() {
	printf("n = %d, k = %d\n", N, K);

	int **columnSizes = NULL;
	int returnSize = 0;
	int **results = combine(N, K, columnSizes, &returnSize);
	int i, j;

	printf("[\n");

	for (i = 0; i < returnSize; i++) {
		printf("  [ ");

		for (j = 0; j < K; j++) {
			printf("%d ", results[i][j]);
		}

		printf("]\n");
	}

	printf("]\n");
}

void combinations() {
	_run();
}

