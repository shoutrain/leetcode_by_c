/*
 * nim_game.c
 *
 *  Created on: Dec 18, 2015
 *      Author: rafael
 */

#include "nim_game.h"

bool canWinNim(int n) {
	if (n % 4 == 0) {
		return false;
	}

	return true;
}

static void _run() {
	int n = 8;

	if (canWinNim(n)) {
		printf("You can win with n = 9\n");
	} else {
		printf("You cannot win with n = 9\n");
	}
}

void nim_game() {
	_run();
}
