#include <iostream>
#include <algorithm>
#include <stack>
#include "graphCycles.h"
#include "graphs.h"

namespace graphcycles {

	Cycle::Cycle(std::vector<int> path, int cost) {
		// Save path & traversal cost
		std::reverse(path.begin(), path.end());
		this->path = std::vector<int>(path);
		this->cost = cost;

		// Create mask
		std::sort(path.begin(), path.end()-1);
		this->mask = "";

		for (int i = 0; i < path.size() - 1; i++) 
			mask += std::to_string(path[i]) + ' ';
	}

	void detect(std::vector<Cycle>& c, graphs::Graph& g) {
		// Data structures
		std::map<int, bool> visited;
		std::stack<std::pair<int, int>> currPath;

		// Try to run dfs on each vertice
		for (auto a : g.connections) {
			int vertice = a.first;
			dfs(currPath, visited, c, g, vertice, 0);
		}
	}

	void dfs(std::stack<std::pair<int, int>>& currPath, std::map<int, bool>& visited, std::vector<Cycle>& c, graphs::Graph& g, int v, int cost) {
		// Vertice already processed
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
			visited[v] = true;
			for (graphs::Edge e : g.connections[v]) {
				dfs(currPath, visited, c, g, e.vertice, e.weight);
			}
			visited[v] = false;
		}

		currPath.pop();
	}
}
