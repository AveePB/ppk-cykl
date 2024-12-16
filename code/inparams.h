#pragma once
#ifndef PARAMS_H
#define PARAMS_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

namespace inparams {

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
    void load(std::vector<std::string>& params, std::string& inFile, std::string& outFile, std::string cycleFile);
}
#endif