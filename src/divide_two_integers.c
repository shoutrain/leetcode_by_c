/*
 * divide_two_integers.c
 *
 *  Created on: Jan 13, 2016
 *      Author: rafael
 */

#include "divide_two_integers.h"

int divide(int dividend, int divisor) {
	if (0 == divisor) {
		return INT_MAX;
	}

	if (0 == dividend) {
		return 0;
	}

	long long a = dividend;
	long long b = divisor;
	long long c = a > 0 ? a : -a;
	long long d = b > 0 ? b : -b;
	long long sum = 0;
	int count = 0;
	long long result = 0;

	while (c >= d) {
		sum = d;
		count = 1;

		while (sum + sum <= c) {
			sum += sum;
			count += count;
		}

		c -= sum;
		result += count;
	}

	if ((dividend < 0 && divisor > 0)
			|| (dividend > 0 && divisor < 0)) {
		result = -result;
	}

	if (INT_MIN == result) {
		return INT_MAX;
	}

	return result;
}

#define DIVID_END -2147483648
#define DIVISOR -1

static void _run() {
	printf("%lld / %lld = %lld\n", (long long)DIVID_END, (long long)DIVISOR,
			(long long)divide(DIVID_END, DIVISOR));
}

void divide_two_integers() {
	_run();
}
