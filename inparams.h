#pragma once
#ifndef PARAMS_H
#define PARAMS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

namespace inparams {

    // Declare global variables
    extern std::string inFile;
    extern std::string outFile;
    extern std::string cycleFile;

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
    void load(std::vector<std::string>& params);

}
#endif