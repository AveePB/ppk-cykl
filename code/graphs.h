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
		 * @return Returns true if the parsing is successful, false otherwise.
		 */
		bool load(std::string filename);

		/**
		 * @brief Parses an edge string in the format "from -> to : weight" and extracts the values for from, to, and weight.
		 *
		 * This function uses a regular expression to match the edge string, extracts the individual values (from, to, and weight),
		 * and stores them in the provided reference variables. If the string is in an invalid format, it returns false.
		 *
		 * @param edgeData The edge string to be parsed (in the format "from -> to : weight").
		 * @param from A reference variable to store the parsed 'from' vertex.
		 * @param to A reference variable to store the parsed 'to' vertex.
		 * @param weight A reference variable to store the parsed edge weight.
		 * @return Returns true if the parsing is successful, false otherwise.
		 */
		bool parseEdge(const std::string& edgeData, int& from, int& to, int& weight);

		/**
		 * @brief Saves the current graph structure to a file.
		 *
		 * This function writes the graph's current connections to the specified file.
		 * @param filename The path to the file to save the graph data.
		 */
		void save(std::string filename);
	};
}
#endif
