/*
 * is_isomorphic.c
 *
 *  Created on: Dec 25, 2015
 *      Author: rafael
 */

#include "is_isomorphic.h"

bool isIsomorphic(char *s, char *t) {
	int sLength = strlen(s);
	int tLength = strlen(s);

	if (sLength != tLength) {
		return false;
	}

	int i = 0;
	char sMap[256] = { '\0' };
	char tMap[256] = { '\0' };

	for (; i < sLength; i++) {
		if (sMap[(int)s[i]] == '\0') {
			sMap[(int)s[i]] = t[i];
		} else {
			if (sMap[(int)s[i]] != t[i]) {
				return false;
			}
		}

		if (tMap[(int)t[i]] == '\0') {
			tMap[(int)t[i]] = s[i];
		} else {
			if (tMap[(int)t[i]] != s[i]) {
				return false;
			}
		}
	}

	return true;
}

static void _run() {
	if (isIsomorphic("abaa", "ctct")) {
		printf("true\n");
	} else {
		printf("false\n");
	}
}

void is_isomorphic() {
	_run();
}
