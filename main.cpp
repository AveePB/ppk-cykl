#include <iostream>
#include <string>
#include <vector>
#include "inparams.h"
#include "graphs.h"
#include "graphEditor.h"

// Declare constants
const char SAVE_AND_EXIT = '0';
const char ADD_NEW_VERTICE = '1';
const char REMOVE_VERTICE = '2';
const char ADD_NEW_EDGE = '3';
const char REMOVE_EDGE = '4';
const char UPDATE_EDGE_WEIGHT = '5';
const char DETECT_CYCLES = '6';
const char FIND_SHORTEST_PATH = '7';
const char FIND_LONGEST_PATH = '8';

/**
 * @brief Prints out a help menu to the console.
 */
void printHelpMenu();

int main(int argc, char** argv) {
	// Load file arguments
	std::vector<std::string> args(argv, argv + argc);
	inparams::load(args);

	// Construct graph from scratch
	graphs::Graph graph;
	bool isDataLoaded = graph.load(inparams::inFile);

	// Handle missing input file
	if (!isDataLoaded) {
		std::string ans;
		std::cout << "Niewczytano pliku z grafem...\n";
		std::cout << "Jesli chcesz kontynuowac, napisz \"tak\": ";
		std::cin >> ans;

		// Exit if not accepted
		if (ans == "tak") isDataLoaded = true;
	}

	// Graph query loop
	while (isDataLoaded) {
		// Declare variables
		char command;

		// Reset terminal window
		system("cls");
		printHelpMenu();
		std::cin.clear();

		// Function launcher
		std::cout << "Wykonaj funkcje: ";
		std::cin >> command;
		if (std::cin.fail()) continue;

		// Task handler
		if (command == SAVE_AND_EXIT) break;

		else if (command == ADD_NEW_VERTICE) grapheditor::addNewVertice(graph);

		else if (command == REMOVE_VERTICE) grapheditor::removeVertice(graph);

		else if (command == ADD_NEW_EDGE) grapheditor::addNewEdge(graph);

		else if (command == REMOVE_EDGE) grapheditor::removeEdge(graph);

		else if (command == UPDATE_EDGE_WEIGHT) grapheditor::updateEdgeWeight(graph);

		else if (command == FIND_SHORTEST_PATH) { }

		else if (command == FIND_LONGEST_PATH) { }

	}

	// Save current graph state
	graph.save(inparams::outFile);

	return 0;
}

void printHelpMenu() {
	std::cout << "================== POMOC ==================\n";
	std::cout << "Program do zarzadzania grafem skierowanym.\n";
	std::cout << "-------------------------------------------\n";
	std::cout << "Funkcje programu:\n";
	std::cout << "0. Zapisz i zakoncz\n";
	std::cout << "1. Dodaj nowy wierzcholek\n";
	std::cout << "2. Usun wierzcholek\n";
	std::cout << "3. Dodaj nowa krawedz\n";
	std::cout << "4. Usun krawedz\n";
	std::cout << "5. Edytuj wage krawedzi\n";
	std::cout << "6. Wyznacz cykle w grafie\n";
	std::cout << "7. Wyznacz najkrotsza sciezke cykliczna\n";
	std::cout << "8. Wyznacz najdluzsza sciezke cykliczna\n";
	std::cout << "-------------------------------------------\n";
	std::cout << "Aby uruchomic dana funkcje, podaj jej numer.\n";
	std::cout << "===========================================\n";
}
