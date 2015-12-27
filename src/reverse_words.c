/*
 * reverse_words.c
 *
 *  Created on: Dec 27, 2015
 *      Author: rafael
 */

#include "reverse_words.h"

static void _moveBack(char *s, int *length, int offset) {
	int i = 0;

	*length -= offset;

	for (; i < *length; i++) {
		s[i] = s[i + offset];
	}

	s[i] = '\0';
}

static void _handleSpaces(char *s, int *length) {
	int offset = 0;

	// remove the leading spaces
	while (' ' == s[offset]) {
		offset++;
	}

	if (offset > 0) {
		_moveBack(s, length, offset);
	}

	// remove the trailing spaces
	while (' ' == s[*length - 1]) {
		(*length)--;
		s[*length] = '\0';
	}

	// remove >1 spaces between words
	char *p = s;
	char *start = NULL;
	char *end = NULL;

	while ('\0' != *p) {
		if (' ' == *p) {
			if (NULL == start) {
				start = p;
			}
		} else {
			if (NULL != start) {
				end = p;
			}
		}

		if (NULL != end) {
			offset = end - start - 1;

			// >1 spaces between the words
			if (offset > 0) {
				_moveBack(start + 1, length, offset);
				p -= offset;
			}

			start = NULL;
			end = NULL;
		}

		p++;
	}

}

static void _reverse(char *s, int length) {
	int i = 0;
	int halfLength = length / 2;

	for (; i < halfLength; i++) {
		s[i] ^= s[length - i - 1];
		s[length - i - 1] ^= s[i];
		s[i] ^= s[length - i - 1];
	}
}

void reverseWords(char *s) {
	if (NULL == s || '\0' == s[0]) {
		return;
	}

	int length = strlen(s);

	_handleSpaces(s, &length);

	if (length > 1) {
		_reverse(s, length);

		char *start = NULL;
		char *end = NULL;

		while (true) {
			if (' ' == *s || '\0' == *s) {
				end = s;
			} else {
				if (NULL == start) {
					start = s;
				}
			}

			if (NULL != end) {
				_reverse(start, end - start);
				start = NULL;
				end = NULL;
			}

			if ('\0' == *s) {
				break;
			}

			s++;
		}
	}
}

static void _run() {
	char s[] = "   a   b ";

	printf("Before reverse: %s\n", s);
	reverseWords(s);
	printf("After reverse: %s\n", s);
}

void reverse_words() {
	_run();
}
