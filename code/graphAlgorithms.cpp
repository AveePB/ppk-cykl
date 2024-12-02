#include <iostream>
#include <fstream>
#include <set>
#include "graphAlgorithms.h"
#include "graphCycles.h"

namespace graphalgo {

	// Declare constants
	const int INF = 2e9; 
	const int NINF = -2e9;

	// Declare functions
	void detectCycles(graphs::Graph& g, std::string filename) { 
		// Initialize variables
		std::vector<graphcycles::Cycle> c;
		std::set<std::string > uniqueMasks;
		std::ofstream outFile(filename);

		graphcycles::detect(c, g);

		for (auto a : c) {
			// Cycle already saved
			if (uniqueMasks.count(a.mask)) continue;

			// Save new cycle
			uniqueMasks.insert(a.mask);
			outFile << "Suma cyklu: " << a.cost << ", sciezka: ";
			for (auto vertice : a.path) {
				outFile << vertice << ' ';
			}
			outFile << '\n';
		}
		outFile.close();
		std::cout << "Wykryte cykle zostaly zapisane do pliku " << filename << '\n';
	}

	void findLongestCyclicPath(graphs::Graph& g) { 
		// Initialize variables
		std::vector<graphcycles::Cycle> c;
		std::vector<int> bestPath;
		int bestCost = NINF;

		// Analyze cycles
		graphcycles::detect(c, g);
		for (auto a : c) {
			// Ignore cycle
			if (a.cost <= bestCost) continue;

			// Update cycle
			bestCost = a.cost;
			bestPath = std::vector<int>(a.path);
		}

		if (bestCost != NINF) {
			std::cout << "Najdluzsza sciezka cykliczna o sumie (" << bestCost << "):\n";
			for (auto v : bestPath)
				std::cout << v << ' ';
			std::cout << '\n';
		}
		else {
			std::cout << "Graf nie posiada zadnych cylki!\n";
		}
	}

	void findShortestCyclicPath(graphs::Graph& g) { 
		// Initialize variables
		std::vector<graphcycles::Cycle> c;
		std::vector<int> bestPath;
		int bestCost = INF;

		// Analyze cycles
		graphcycles::detect(c, g);
		for (auto a : c) {
			// Ignore cycle
			if (a.cost >= bestCost) continue;

			// Update cycle
			bestCost = a.cost;
			bestPath = std::vector<int>(a.path);
		}
		if (bestCost != INF) {
			std::cout << "Najkrotsza sciezka cykliczna o sumie (" << bestCost << "):\n";
			for (auto v : bestPath)
				std::cout << v << ' ';
			std::cout << '\n';
		}
		else {
			std::cout << "Graf nie posiada zadnych cylki!\n";
		}
	}
}
