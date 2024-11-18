#include <iostream>
#include <stack>
#include "graphCycles.h"
#include "graphs.h"

namespace graphcycles {

	Cycle::Cycle(std::vector<int> path, int cost) : path(path), cost(cost) {}

	static void detect(std::vector<Cycle>& c, graphs::Graph& g) {
		// Resest data structures
		while (!currPath.empty()) currPath.pop();
		analyzed.clear();
		visited.clear();

		// Try to run dfs on each vertice
		for (auto a : g.connections) {
			int vertice = a.first;
			dfs(c, g, vertice, 0);
		}
	}

	static void dfs(std::vector<Cycle>& c, graphs::Graph& g, int v, int cost) {
		// Vertice already processed
		if (analyzed[v]) return;

		currPath.push({ v, cost });

		// Detected new cycle
		if (visited[v]) {
			std::vector<int> nodes, costs;
			int sum = cost;

			// Remove first element
			nodes.push_back(v);
			costs.push_back(cost);
			currPath.pop();


			// Find the path
			while (!currPath.empty()) {
				// Remove top element
				std::pair<int, int> node = currPath.top();
				currPath.pop();

				// Save cycle data
				nodes.push_back(node.first);
				costs.push_back(node.second);
				sum += node.second;

				// Meet dead end
				if (node.first == v) break;
			}

			// Restore the current path
			for (int i = nodes.size() - 1; i >= 0; i--)
				currPath.push({ nodes[i], costs[i] });

			// Save cycle
			c.push_back(Cycle(nodes, sum));
		}

		// Keep looking
		else {
			// Visit all neighbors 
			for (graphs::Edge e : g.connections[v])
				dfs(c, g, e.vertice, e.weight);
		}

		currPath.pop();
	}
}
