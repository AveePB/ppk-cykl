#include "inparams.h"

namespace inparams {

    // Define global variables
    std::string inFile;
    std::string outFile;
    std::string cycleFile;

    /**
     * @brief Parses command-line parameters to set file paths for input, output, and cycle files.
     *
     * This function processes a vector of command-line arguments to extract file paths.
     * It checks for specific flags ("-i" for input, "-o" for output, and "-c" for cycle file)
     * and assigns corresponding values. If any of these paths are not specified,
     * the function prompts the user to enter them manually.
     *
     * @param params: a vector of command-line arguments (each as a string)
     */
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
