/*
 * valid_anagram.c
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#include "valid_anagram.h"

bool isAnagram(char *s, char *t) {
	if (s == NULL && t == NULL) {
		return true;
	} else if (s == NULL || t == NULL) {
		return false;
	}

	int sLen = strlen(s);
	int tLen = strlen(t);

	if (sLen != tLen) {
		return false;
	}

	int i = 0;
	int table[26] = {0};

	for (; i < sLen; i++) {
		table[s[i] - 'a']++;
		table[t[i] - 'a']--;
	}

	for (i = 0; i < 26; i++) {
		if (table[i] != 0) {
			return false;
		}
	}

	return true;
}

static void _run() {
	char *s = "hello";
	char *t = "hlloo";

	if (isAnagram(s, t)) {
		printf("%s and %s is anagram strings\n", s, t);
	} else {
		printf("%s and %s is not anagram strings\n", s, t);
	}
}

void valid_anagram() {
	_run();
}
