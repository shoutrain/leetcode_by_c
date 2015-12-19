/*
 * merge_two_sorted_lists.c
 *
 *  Created on: Dec 19, 2015
 *      Author: rafael
 */

#include "merge_two_sorted_lists.h"

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
	struct ListNode *p = NULL;
	struct ListNode **pos = &p;
	struct ListNode *pos1 = l1;
	struct ListNode *pos2 = l2;

	while (true) {
		if (NULL == pos1) {
			*pos = pos2;
			break;
		} else if (NULL == pos2) {
			*pos = pos1;
			break;
		} else if (pos1->val <= pos2->val) {
			*pos = pos1;
			pos1 = pos1->next;
		} else {
			*pos = pos2;
			pos2 = pos2->next;
		}

		pos = &(*pos)->next;
	}

	return p;
}

static void _printList(struct ListNode *l) {
	printf("[");

	while (NULL != l) {
		printf(" %d", l->val);
		l = l->next;
	}

	printf(" ]\n");
}

static void _run() {
	struct ListNode *l1;
	struct ListNode **pos1 = &l1;
	struct ListNode *l2;
	struct ListNode **pos2 = &l2;
	int i = 0;

	for (i = 1; i <= 5; i++) {
		(*pos1) = (struct ListNode *)malloc(sizeof(struct ListNode));
		(*pos1)->val = i + (i - 1) * 2;
		(*pos1)->next = NULL;
		pos1 = &((*pos1)->next);
	}

	_printList(l1);

	for (i = 1; i <= 5; i++) {
		(*pos2)= (struct ListNode *)malloc(sizeof(struct ListNode));
		(*pos2)->val = i + (i - 1) * 2 + 1;
		(*pos2)->next = NULL;
		pos2 = &((*pos2)->next);
	}

	_printList(l2);

	struct ListNode *l = mergeTwoLists(l1, l2);

	_printList(l);

	// do not need to call free
}

void merge_two_sorted_lists() {
	_run();
}
