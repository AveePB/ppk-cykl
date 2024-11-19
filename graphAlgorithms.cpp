#include <iostream>
#include <set>
#include "graphAlgorithms.h"
#include "graphCycles.h"

namespace graphalgo {

	// Declare constants
	const int INF = 2e9; 
	const int NINF = -2e9;

	// Declare functions
	void detectCycles(graphs::Graph& g, std::string filename) { 
		// Initialize data structures
		std::vector<graphcycles::Cycle> c;
		std::set<std::string > uniqueMasks;

		graphcycles::detect(c, g);

		for (auto a : c) {
			// Cycle already saved
			if (uniqueMasks.count(a.mask)) continue;

			uniqueMasks.insert(a.mask);
			for (auto v : a.path)
				std::cout << v << ' ';
			std::cout << '\n';
		}


	}

	void findLongestCyclicPath(graphs::Graph& g) { }

	void findShortestCyclicPath(graphs::Graph& g) { }
}
