/*
 * merge_two_sorted_lists.h
 *
 *  Created on: Dec 19, 2015
 *      Author: rafael
 */

#ifndef MERGE_TWO_SORTED_LISTS_H_
#define MERGE_TWO_SORTED_LISTS_H_

#include "common.h"

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode *l1, struct ListNode *l2);
void merge_two_sorted_lists();

#endif /* MERGE_TWO_SORTED_LISTS_H_ */
