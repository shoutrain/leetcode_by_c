/*
 * add_digits.c
 *
 *  Created on: Jan 11, 2016
 *      Author: rafael
 */

#include "add_digits.h"

int addDigits(int num) {
	return (num - 1) % 9 + 1;
}

#define NUM 12345

static void _run() {
	printf("%d 's added digits is %d\n", NUM, addDigits(NUM));
}

void add_digits() {
	_run();
}
