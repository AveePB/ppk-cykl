#include "inparams.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

namespace inparams {

    // Define global variables
    std::string inFile;
    std::string outFile;
    std::string cycleFile;

    // Declare load function
    void load(std::vector<std::string>& params) {
        // Reinitialize variables
        inFile = "";
        outFile = "";
        cycleFile = "";

        // Go through parameters
        for (int i = 1; i < params.size(); i++) {

            // Load input filename
            if (params[i] == "-i" && (i + 1 < params.size()))
                inFile = params[i + 1];

            // Load output filename
            else if (params[i] == "-o" && (i + 1 < params.size()))
                outFile = params[i + 1];

            // Load cycle filename
            else if (params[i] == "-c" && (i + 1 < params.size()))
                cycleFile = params[i + 1];
        }

        // Prompt for any missing files
        if (inFile == "") {
            std::cout << "Podaj nazwe pliku wejsciowego: ";
            std::cin >> inFile;
        }

        if (outFile == "") {
            std::cout << "Podaj nazwe pliku wyjsciowego: ";
            std::cin >> outFile;
        }

        if (cycleFile == "") {
            std::cout << "Podaj nazwe pliku z cyklami: ";
            std::cin >> cycleFile;
        }
    }
}

