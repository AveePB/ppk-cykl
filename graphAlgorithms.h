#pragma once
#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#include <iostream>
#include "graphs.h"

namespace graphalgo {
	
	// Declare constants
	extern const int INF, NINF;

	/**
	 * @brief Finds and outputs the longest cyclic path in the graph based on edge weights.
	 *
	 * This function analyzes the graph to detect cycles and calculates the total weight
	 * of each cycle. It then determines the cycle with the maximum total weight and outputs
	 * the path and its weight. If no cycles exist, the function indicates this to the user.
	 *
	 * @param g The directed graph represented as an adjacency list with weighted edges.
	 */
	void findLongestCyclicPath(graphs::Graph& g);

	/**
	 * @brief Finds and outputs the shortest cyclic path in the graph based on edge weights.
	 *
	 * This function analyzes the graph to detect cycles and calculates the total weight
	 * of each cycle. It then determines the cycle with the minimum total weight and outputs
	 * the path and its weight. If no cycles exist, the function indicates this to the user.
	 *
	 * @param g The directed graph represented as an adjacency list with weighted edges.
	 */
	void findShortestCyclicPath(graphs::Graph& g);
}

#endif