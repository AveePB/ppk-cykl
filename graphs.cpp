#include "graphs.h"
#include <fstream>
#include <sstream>

namespace graphs {

    // Declare struct methods
    Edge::Edge(int vertice, int weight) : vertice(vertice), weight(weight) {}

    void Graph::load(std::string filename) {
        // Declare variables
        std::ifstream file(filename); 
        std::string ans;

        // Try to access file
        if (!file) {
            // Handle missing file warning
            std::cout << "Niewczytano pliku z grafem...\n";
            std::cout << "Jesli chcesz kontynuowac, napisz \"tak\" ";
            std::cin >> ans;

            // Exit if not accepted
            if (ans != "tak") exit(0);
        }
        
        //... handle graph loading
        std::cout << "Wczytano plik\n";
    }

    void Graph::save(std::string filename) { }
    void Graph::detectCycles(std::string filename) { }
}
