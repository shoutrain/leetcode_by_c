/*
 * happy_number.c
 *
 *  Created on: Jan 11, 2016
 *      Author: rafael
 */

#include "happy_number.h"

struct Node {
	int v;
	struct Node *l;
	struct Node *r;
};

static struct Node *_root = NULL;

static void _insertBST(struct Node *node, int v) {
	if (NULL == _root) {
		_root = (struct Node *)malloc(sizeof(struct Node));
		memset(_root, 0, sizeof(struct Node));
		_root->v = v;

		return;
	}

	if (v < node->v) {
		if (NULL == node->l) {
			node->l = (struct Node *)malloc(sizeof(struct Node));
			memset(node->l, 0, sizeof(struct Node));
			node->l->v = v;
		} else {
			_insertBST(node->l, v);
		}
	} else {
		if (NULL == node->r) {
			node->r = (struct Node *)malloc(sizeof(struct Node));
			memset(node->r, 0, sizeof(struct Node));
			node->r->v = v;
		} else {
			_insertBST(node->r, v);
		}
	}
}

static void _freeBST(struct Node *node) {
	if (NULL == node) {
		return;
	}

	if (NULL != node->l) {
		_freeBST(node->l);
	}

	if (NULL != node->r) {
		_freeBST(node->r);
	}

	free(node);
	node = NULL;
}

static bool _judgeBST(struct Node *node, int v) {
	if (NULL == node) {
		return false;
	}

	if (v == node->v) {
		return true;
	}

	if (v < node->v) {
		return _judgeBST(node->l, v);
	} else {
		return _judgeBST(node->r, v);
	}
}

bool isHappy(int n) {
	if (1 > n) {
		return false;
	}

	if (1 == n) {
		return true;
	}

	while (true) {
		int s = 0;

		while (n > 0) {
			int m = n % 10;

			s += m * m;
			n /= 10;
		}

		if (1 == s) {
			return true;
		}

		if (_judgeBST(_root, s)) {
			return false;
		}

		_insertBST(_root, s);
		n = s;
	}
}

#define NUM 13

static void _run() {
	if (isHappy(NUM)) {
		printf("%d is happy number\n", NUM);
	} else {
		printf("%d is not happy number\n", NUM);
	}

	_freeBST(_root);
}

void happy_number() {
	_run();
}
