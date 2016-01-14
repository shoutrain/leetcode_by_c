/*
 * clone_graph.c
 *
 *  Created on: Jan 14, 2016
 *      Author: rafael
 */

#include "clone_graph.h"

#define HASH_TABLE_SIZE 65535

struct HTNode {
	int key;
	void *value;
	struct HTNode *next;
};

static struct HTNode *_hashTable[HASH_TABLE_SIZE];

static unsigned short _htHash(int key) {
	unsigned short first = 0x0000FFFF & key;
	unsigned short second = key >> 16;

	return first ^ second;
}

static void _htClear(struct HTNode *node) {
	if (NULL != node) {
		_htClear(node->next);
	}

	free(node);
}

void _htInit() {
	memset(_hashTable, 0, sizeof(_hashTable));
}

void _htDeinit() {
	int i = 0;

	for (; i < HASH_TABLE_SIZE; i++) {
		_htClear(_hashTable[i]);
	}
}

bool _htInsert(int key, void *value) {
	unsigned short hashKey = _htHash(key);

	if (NULL == _hashTable[hashKey]) {
		_hashTable[hashKey] = (struct HTNode *)malloc(sizeof(struct HTNode));
		_hashTable[hashKey]->key = key;
		_hashTable[hashKey]->value = value;
		_hashTable[hashKey]->next = NULL;

		return true;
	} else {
		struct HTNode **pp = &_hashTable[hashKey];

		do {
			if ((*pp)->key == key) {
				return false;
			}

			*pp = (*pp)->next;
		} while (NULL != *pp);

		*pp = (struct HTNode *)malloc(sizeof(struct HTNode));
		(*pp)->key = key;
		(*pp)->value = value;
		(*pp)->next = NULL;

		return true;
	}
}

bool _htDel(int key) {
	unsigned short hashKey = _htHash(key);

	if (NULL == _hashTable[hashKey]) {
		return false;
	}

	struct HTNode **pp = &_hashTable[hashKey];

	do {
		if ((*pp)->key == key) {
			struct HTNode *q = *pp;

			if (NULL != (*pp)->next) {
				*pp = (*pp)->next;
			} else {
				*pp = NULL;
			}

			free(q);

			return true;
		}

		*pp = (*pp)->next;
	} while (NULL != *pp);

	return false;
}

void *_htFind(int key) {
	unsigned short hashKey = _htHash(key);

	if (NULL == _hashTable[hashKey]) {
		return false;
	}

	struct HTNode *p = _hashTable[hashKey];

	do {
		if (p->key == key) {
			return p->value;
		}

		p = p->next;
	} while (NULL != p);

	return NULL;
}

struct UndirectedGraphNode *cloneGraph(struct UndirectedGraphNode *graph) {
	if (NULL == graph) {
		return NULL;
	}

	if (_htFind(graph->label)) {
		return NULL;
	}

	struct UndirectedGraphNode *node = (struct UndirectedGraphNode *)
			malloc(sizeof(struct UndirectedGraphNode));
	int i = 0;

	memset(node, 0, sizeof(struct UndirectedGraphNode));
	_htInsert(graph->label, node);
	node->label = graph->label;
	node->neighborsCount = graph->neighborsCount;

	for (; i < graph->neighborsCount; i++) {
		struct UndirectedGraphNode *p = _htFind(graph->neighbors[i]->label);

		if (NULL != p) {
			node->neighbors[i] = p;
		} else {
			node->neighbors[i] = cloneGraph(graph->neighbors[i]);
		}
	}

	return node;
}

static void _run() {
	_htInit();

	struct UndirectedGraphNode node1;
	struct UndirectedGraphNode node2;
	struct UndirectedGraphNode node3;

	memset(&node1, 0, sizeof(struct UndirectedGraphNode));
	node1.label = 0;
	node1.neighbors[0] = &node2;
	node1.neighborsCount = 1;

	memset(&node2, 0, sizeof(struct UndirectedGraphNode));
	node2.label = 1;
	node2.neighbors[0] = &node3;
	node2.neighborsCount = 1;

	memset(&node3, 0, sizeof(struct UndirectedGraphNode));
	node3.label = 2;
	node3.neighbors[0] = &node3;
	node3.neighborsCount = 1;

	struct UndirectedGraphNode *graph = cloneGraph(&node1);

	free(graph); // just freed the first one
	// TODO free more

	_htDeinit();
}

void clone_graph() {
	_run();
}
