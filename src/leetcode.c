/*
 ============================================================================
 Name        : leetcode.c
 Author      : Rafael Gu
 Version     :
 Copyright   : Free
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "interleaving_string.h"

int main(void) {
	if (isInterleave("aabcc", "dbbca", "aadbbcbcac")) {
		printf("Is Interleaving String\n");
	} else {
		printf("Is not Interleaving String\n");
	}

	puts(""); /* prints  */

	return EXIT_SUCCESS;
}
