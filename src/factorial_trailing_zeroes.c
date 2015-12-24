/*
 * factorial_trailing_zeroes.c
 *
 *  Created on: Dec 24, 2015
 *      Author: rafael
 */

#include "factorial_trailing_zeroes.h"

int trailingZeroes(int n) {
	if (n < 5) {
		return 0;
	}

	int m = n / 5;

	return m + trailingZeroes(m);
}

#define NUMBERS 1000

static void _run() {
	printf("%d's factorial trailing zeroes: %d\n", NUMBERS,
			trailingZeroes(NUMBERS));
}

void factorial_trailing_zeroes() {
	_run();
}
