/*
 * reverse_linked_list.c
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#ifndef REVERSE_LINKED_LIST_C_
#define REVERSE_LINKED_LIST_C_

#include "reverse_linked_list.h"

struct ListNode *reverseList(struct ListNode *head) {
	if (NULL == head || NULL == head->next) {
		return head;
	}

	struct ListNode *p = reverseList(head->next);

	head->next->next = head;
	head->next = NULL;

	return p;
}

static void _run() {
	// do nothing
}

void reverse_linked_list() {
	_run();
}

#endif /* REVERSE_LINKED_LIST_C_ */
