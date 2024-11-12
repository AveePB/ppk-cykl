#include "inparams.h"

namespace inparams {

    // Define global variables
    std::string inFile;
    std::string outFile;
    std::string cycleFile;

    // Define the load function
    void load(std::vector<std::string> params) {
        // Reinitialize variables
        inFile = "";
        outFile = "";
        cycleFile = "";

        // Go through parameters
        for (int i = 1; i < params.size(); i++) {
            // Load input file
            if (params[i] == "-i" && (i + 1 < params.size())) 
                inFile = params[i + 1];
            
            // Load output file
            else if (params[i] == "-o" && (i + 1 < params.size())) 
                outFile = params[i + 1];
            
            // Load cycle file
            else if (params[i] == "-c" && (i + 1 < params.size()))
                cycleFile = params[i + 1];
        }

        // Check input file
        if (inFile == "") {
            std::cout << "Podaj nazwe pliku wejsciowego: ";
            std::cin >> inFile;
        }

        // Check output file
        if (outFile == "") {
            std::cout << "Podaj nazwe pliku wyjsciowego: ";
            std::cin >> outFile;
        }

        // Check cycle file
        if (cycleFile == "") {
            std::cout << "Podaj nazwe pliku z cyklami: ";
            std::cin >> cycleFile;
        }
    }
}