#pragma once
#ifndef GRAPH_CYCLES_H
#define GRAPH_CYCLES_H

#include <iostream>
#include <string>
#include <stack>
#include "graphs.h"

namespace graphcycles {

	// Define structs
	struct Cycle {
		std::vector<int> path;
		std::string mask;
		int cost;

		/**
		 * @brief Constructs a cycle with a specified path and cost.
		 *
		 * @param path The cycle path.
		 * @param weight The traversal cost of cycle.
		 */
		Cycle(std::vector<int> path, int cost);
	};

	// Data structures
	extern std::map<int, bool> visited;
	extern std::stack<std::pair<int, int>> currPath;

	/**
	 * @brief Analyzes a graph in order to find all unique cycles and its costs.
	 * 
	 * @param c The detected cycles.
	 * @param g The analyzed graph. 
	 */
	void detect(std::vector<Cycle>& c, graphs::Graph& g);

	/**
	 * @brief Processes given vertice and constructs possible cycle paths.
	 * 
	 * @param c The detected cycles.
	 * @param g The analyzed graph.
	 * @param v The current vertice.
	 * @param cost The required cost to get to this vertice. 
	 */
	void dfs(std::vector<Cycle>& c, graphs::Graph& g, int v, int cost);
}

#endif 
