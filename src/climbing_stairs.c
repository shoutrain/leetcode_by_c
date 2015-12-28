/*
 * climbing_stairs.c
 *
 *  Created on: Dec 28, 2015
 *      Author: rafael
 */

#include "climbing_stairs.h"

int climbStairs(int n) {
	if (n == 0) {
		return n;
	}

	int i = 2;
	int *v = (int *)malloc(n * sizeof(int));

	v[0] = 1;
	v[1] = 2;

	for (i = 2; i < n; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}

	return v[n - 1];
}

#define NUM 44

static void _run() {
	printf("%d kinds of distinct ways for %d stairs\n", climbStairs(NUM), NUM);
}

void climbing_stairs() {
	_run();
}
