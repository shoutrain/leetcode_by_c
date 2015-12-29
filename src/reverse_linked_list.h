/*
 * reverse_linked_list.h
 *
 *  Created on: Dec 29, 2015
 *      Author: rafael
 */

#ifndef REVERSE_LINKED_LIST_H_
#define REVERSE_LINKED_LIST_H_

#include "common.h"
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head);
void reverse_linked_list();

#endif /* REVERSE_LINKED_LIST_H_ */
