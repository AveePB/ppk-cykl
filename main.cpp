#include <iostream>
#include <string>
#include <vector>
#include "inparams.h"
#include "graphs.h"

int main(int argc, char** argv) {
	// Load file arguments
	std::vector<std::string> args(argv, argv + argc);
	inparams::load(args);

	// Construct graph from scratch
	graphs::Graph graph;
	bool isInputFile = graph.load(inparams::inFile);

	// Handle missing input file
	if (!isInputFile) {
		std::string ans;
		std::cout << "Niewczytano pliku z grafem...\n";
		std::cout << "Jesli chcesz kontynuowac, napisz \"tak\" ";
		std::cin >> ans;

		// Exit if not accepted
		if (ans != "tak") return 0;
	}

	char c;
	std::cin >> c;

	return 0;
}