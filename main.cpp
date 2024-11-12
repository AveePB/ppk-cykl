#include <iostream>
#include <string>
#include <vector>
#include "inparams.h"

int main(int argc, char** argv) {
	// Load file arguments
	std::vector<std::string> args(argv, argv + argc);
	inparams::load(args);



	return 0;
}