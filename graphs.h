#pragma once
#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include <vector>
#include <map>

namespace graphs {
	
	// Define structures
	struct Edge {
		int vertice, weight;

		/**
		 * @brief Constructs an edge with a specified vertice and weight.
		 *
		 * @param vertice The destination vertice.
		 * @param weight The weight of the edge.
		 */
		Edge(int vertice, int weight);
	};

	struct Graph {
		std::map<int, std::vector<Edge>> connections;

		/**
		 * @brief Loads a graph structure from a file.
		 *
		 * This function reads the graph data from the specified file and initializes the connections accordingly.
		 * @param filename The path to the file containing the graph data.
		 */
		void load(std::string filename);

		/**
		 * @brief Saves the current graph structure to a file.
		 *
		 * This function writes the graph's current connections to the specified file.
		 * @param filename The path to the file to save the graph data.
		 */
		void save(std::string filename);

		/**
		 * @brief Detects cycles within the graph and saves the result to a file.
		 *
		 * This function performs a cycle detection algorithm on the graph and writes any cycles found to the specified file.
		 * @param filename The path to the file to save cycle detection results.
		 */
		void detectCycles(std::string filename);

		// Declare update functions
		// ...
	};
}
#endif
