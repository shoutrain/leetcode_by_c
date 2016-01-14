/*
 * clone_graph.h
 *
 *  Created on: Jan 14, 2016
 *      Author: rafael
 */

#ifndef CLONE_GRAPH_H_
#define CLONE_GRAPH_H_

#include "common.h"

#define NEIGHBORS_MAX_SIZE 100

struct UndirectedGraphNode {
    int label;
    struct UndirectedGraphNode *neighbors[NEIGHBORS_MAX_SIZE];
    int neighborsCount;
};

struct UndirectedGraphNode *cloneGraph(struct UndirectedGraphNode *graph);
void clone_graph();

#endif /* CLONE_GRAPH_H_ */
