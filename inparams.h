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

    // Declare function
    void load(std::vector<std::string> params);

}
#endif