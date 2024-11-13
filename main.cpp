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
	graph.load(inparams::inFile);

	//

	return 0;
}