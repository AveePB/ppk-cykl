#include "graphEditor.h"

namespace grapheditor {

	void addNewVertice(graphs::Graph& g) {
		// Initialize variables
		int newV;

		// Load new vertice
		std::cout << "Podaj nowy wierzcholek: ";
		std::cin >> newV;

		// Failed to load vertice
		if (std::cin.fail()) {
			std::cout << "Podales nieprawidlowy wierzcholek!\n";
			return;
		}

		// Vertice already exists
		if (g.connections.find(newV) != g.connections.end()) {
			std::cout << "Wierzcholek juz istnieje!\n";
			return;
		}

		// Safety checks
		if (newV < 0) {
			std::cout << "Wierzcholek nie moze byc ujemny!\n";
			return;
		}

		// Create new vertice
		g.connections[newV] = std::vector<graphs::Edge>();
		std::cout << "Dodano nowy wierzcholek do grafu\n";
	}

	void removeVertice(graphs::Graph& g) {
		// Initialize variables
		int vToDel;

		// Load new vertice
		std::cout << "Podaj numer wierzcholka: ";
		std::cin >> vToDel;

		// Failed to load vertice
		if (std::cin.fail()) {
			std::cout << "Podales nieprawidlowy wierzcholek!\n";
			return;
		}

		// Vertice doesn't exist
		if (g.connections.find(vToDel) == g.connections.end()) {
			std::cout << "Wierzcholek nie istnieje!\n";
			return;
		}

		// Delete vertice
		g.connections.erase(vToDel);

		// Go through all nodes in graph
		for (auto it = g.connections.begin(); it != g.connections.end(); it++) {
			// Get current vertice
			int currV = it->first;

			// Remove edges connected to vToDel 
			g.connections[currV].erase(
				std::remove_if(
					g.connections[currV].begin(), // First Elm.
					g.connections[currV].end(), // Last Elm.
					
					// Check if edge is connected to vToDel
					[vToDel](graphs::Edge e) { 
						return e.vertice == vToDel;
					}
				),
				g.connections[currV].end() // End of vector
			);
		}

		std::cout << "Usunieto wierzcholek z grafu\n";
	}

	void addNewEdge(graphs::Graph& g) {
		// Initialize variables
		int v1, v2, weight;
		
		// Load first vertice
		std::cout << "Podaj pierwszy wierzcholek: ";
		std::cin >> v1;

		if (std::cin.fail()) {
			std::cout << "Podales nieprawidlowy wierzcholek!\n";
			return;
		}

		// Load second vertice
		std::cout << "Podaj drugi wierzcholek: ";
		std::cin >> v2;

		if (std::cin.fail()) {
			std::cout << "Podales nieprawidlowy wierzcholek!\n";
			return;
		}

		// Load edge weight
		std::cout << "Podaj wage krawedzi: ";
		std::cin >> weight;

		if (std::cin.fail()) {
			std::cout << "Podales nieprawidlowa wage!\n";
			return;
		}

		// Safety checks
		if (v1 < 0 || v2 < 0) {
			std::cout << "Wierzcholek nie moze byc ujemny!\n";
			return;
		}

		if (weight < 0) {
			std::cout << "Waga krawedzi nie moze byc ujemna!\n";
			return;
		}

		if (g.connections.find(v1) == g.connections.end() || g.connections.find(v2) == g.connections.end()) {
			std::cout << "Ktorys z wierzcholkow nie istnieje w grafie!\n";
			return;
		}

		// Create new connection
		g.connections[v1].push_back(graphs::Edge(v2, weight));
		std::cout << "Dodano nowa krawedz w grafie\n";
	}
	
	void removeEdge(graphs::Graph& g) {
		// Initialize variables
		int v1, v2, weight;

		// Load first vertice
		std::cout << "Podaj pierwszy wierzcholek: ";
		std::cin >> v1;

		if (std::cin.fail()) {
			std::cout << "Podales nieprawidlowy wierzcholek!\n";
			return;
		}

		// Load second vertice
		std::cout << "Podaj drugi wierzcholek: ";
		std::cin >> v2;

		if (std::cin.fail()) {
			std::cout << "Podales nieprawidlowy wierzcholek!\n";
			return;
		}

		// Load edge weight
		std::cout << "Podaj wage krawedzi: ";
		std::cin >> weight;

		if (std::cin.fail()) {
			std::cout << "Podales nieprawidlowa wage!\n";
			return;
		}

		// Safety checks
		if (v1 < 0 || v2 < 0) {
			std::cout << "Wierzcholek nie moze byc ujemny!\n";
			return;
		}

		if (weight < 0) {
			std::cout << "Waga krawedzi nie moze byc ujemna!\n";
			return;
		}

		if (g.connections.find(v1) == g.connections.end() || g.connections.find(v2) == g.connections.end()) {
			std::cout << "Ktorys z wierzcholkow nie istnieje w grafie!\n";
			return;
		}

		// Remove edge connected to v2 (with specified weight) 
		g.connections[v1].erase(
			std::remove_if(
				g.connections[v1].begin(), // First Elm.
				g.connections[v1].end(), // Last Elm.

				// Check if edge is connected to vToDel
				[v2, weight](graphs::Edge e) {
					return e.vertice == v2 && e.weight == weight;
				}
			),
			g.connections[v1].end() // End of vector
		);

		std::cout << "Dokonano operacji usuniecia krawedzi z grafu\n";
	}

	void updateEdgeWeight(graphs::Graph& g) {
		// Initialize variables
		int v1, v2, weight;

		// Load first vertice
		std::cout << "Podaj pierwszy wierzcholek: ";
		std::cin >> v1;

		if (std::cin.fail()) {
			std::cout << "Podales nieprawidlowy wierzcholek!\n";
			return;
		}

		// Load second vertice
		std::cout << "Podaj drugi wierzcholek: ";
		std::cin >> v2;

		if (std::cin.fail()) {
			std::cout << "Podales nieprawidlowy wierzcholek!\n";
			return;
		}

		// Load edge weight
		std::cout << "Podaj aktualna wage krawedzi: ";
		std::cin >> weight;

		if (std::cin.fail()) {
			std::cout << "Podales nieprawidlowa wage!\n";
			return;
		}

		// Safety checks
		if (v1 < 0 || v2 < 0) {
			std::cout << "Wierzcholek nie moze byc ujemny!\n";
			return;
		}

		if (weight < 0) {
			std::cout << "Waga krawedzi nie moze byc ujemna!\n";
			return;
		}

		if (g.connections.find(v1) == g.connections.end() || g.connections.find(v2) == g.connections.end()) {
			std::cout << "Ktorys z wierzcholkow nie istnieje w grafie!\n";
			return;
		}
		
		// Go through all edges
		int n = g.connections[v1].size();
		bool anyUpdate = false;

		for (int i = 0; i < n; i++) {
			// Update weight
			if (g.connections[v1][i].vertice == v2 && g.connections[v1][i].weight == weight) {
				int newWeight = 0;
				std::cout << "Znaleziono krawedz!\n";
				std::cout << "Podaj nowa wage: ";
				std::cin >> newWeight;
				
				// Safety checks
				if (std::cin.fail()) {
					std::cout << "Podales nieprawidlowa wage!\n";
					return;
				}

				if (newWeight < 0) {
					std::cout << "Waga krawedzi nie moze byc ujemna!\n";
					return;
				}

				// Overwrite old weight
				g.connections[v1][i].weight = newWeight;
				anyUpdate = true;
				std::cout << "Przypisana nowa wage\n";
			}
		}

		// No updates
		if (!anyUpdate) 
			std::cout << "Zadna krawedz nie zostala zaktualizowana!\n";
	}
}
