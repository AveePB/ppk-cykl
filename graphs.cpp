#include "graphs.h"
#include <fstream>
#include <sstream>
#include <regex>

namespace graphs {

    // Declare struct methods
    Edge::Edge(int vertice, int weight) : vertice(vertice), weight(weight) {}

    bool Graph::load(std::string filename) {
        // Declare variables
        std::ifstream file(filename); 
        std::string ans;

        // Try to access file
        if (!file) return false;
        
        // Create string to store clean data
        std::string formatedData = "";
        char ch;
            
        // Process each char in input file
        while (file.get(ch)) {
            
            // Skip spaces and newlines
            if (ch == ' ' || ch == '\n' || ch == '\r') continue;

            // Add valid char
            formatedData += ch;
        }
        
        // Close input file
        file.close();
        
        // Parse graph vertices
        std::string edge;
        std::istringstream edgeStream(formatedData);

        while (std::getline(edgeStream, edge, ',')) {
            
            // Initialize edge data
            int from, to, weight;

            // Failed to prase edge
            if (!parseEdge(edge, from, to, weight)) return false;
            
            // Add new element
            connections[from].push_back(Edge(to, weight));
        }
        return true;
    }

    bool Graph::parseEdge(const std::string& edgeData, int& from, int& to, int& weight) {
        // Regular expression to parse edge in form "from -> to : weight"
        std::regex edgePattern(R"((\d+)\s*->\s*(\d+)\s*:\s*(\d+))");
        std::smatch match;

        // If edge matches pattern
        if (std::regex_match(edgeData, match, edgePattern)) {
            
            // Extract the integers
            from = std::stoi(match[1].str());
            to = std::stoi(match[2].str());
            weight = std::stoi(match[3].str());

            return true;
        }

        // Invalid format
        return false;
    }

    void Graph::save(std::string filename) { 
        // Declare variables
        std::ofstream file(filename);

        // Go through all nodes in graph
        for (auto it = connections.begin(); it != connections.end(); it++) {
            
            // Get vertice
            int v = it->first;

            // Save edge
            for (Edge e : connections[v])
                file << v << " -> " << e.vertice << " : " << e.weight << ",\n";
        }

        // Close output file
        file.close();
    }

    void Graph::detectCycles(std::string filename) { }
}
