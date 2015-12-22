/*
 * count_of_smaller_numbers_after_self.c
 *
 *  Created on: Dec 18, 2015
 *      Author: rafael
 */

#include "count_of_smaller_numbers_after_self.h"

struct Node {
	int value;
	int lessCount;
	int equalCount;
	struct Node *left;
	struct Node *right;
};

void insert(struct Node *node, int value, int *count) {
	if (value < node->value) {
		node->lessCount++;

		if (0 == node->left) {
			struct Node *newNode= (struct Node *)malloc(sizeof(struct Node));

			memset(newNode, 0, sizeof(struct Node));
			newNode->value = value;
			node->left= newNode;
		} else {
			insert(node->left, value, count);
		}
	} else if (value > node->value) {
		*count += node->lessCount + node->equalCount + 1;

		if (0 == node->right) {
			struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

			memset(newNode, 0, sizeof(struct Node));
			newNode->value = value;
			node->right = newNode;
		} else {
			insert(node->right, value, count);
		}
	} else {
		*count += node->lessCount;
		node->equalCount++;
	}
}

int *countSmaller(int *nums, int numsSize, int *returnSize) {
	int *counts = (int *)malloc(numsSize * sizeof(int));
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	int i = 0;

	memset(node, 0, sizeof(struct Node));
	node->value = nums[numsSize - 1];
	counts[numsSize - 1] = 0;

	for (i = numsSize - 2; i >= 0; i--) {
		int count = 0;

		insert(node, nums[i], &count);
		counts[i] = count;
	}

	*returnSize = numsSize;

	return counts;
}

#define NUM 4

static void _run() {
	int nums[NUM] = {5, 2, 6, 1};
	int returnSize = 0;

	int *counts = countSmaller(nums, NUM, &returnSize);
	int i = 0;

	printf("nums: [");

	for (i = 0; i < NUM; i++) {
		if (0 == i) {
			printf("%d", nums[i]);
		} else {
			printf(",%d", nums[i]);
		}
	}

	printf("]\n");
	printf("counts: [");

	for (i = 0; i < returnSize; i++) {
		if (0 == i) {
			printf("%d", counts[i]);
		} else {
			printf(",%d", counts[i]);
		}
	}

	printf("]\n");
}

void count_of_smaller_numbers_after_self() {
	_run();
}
