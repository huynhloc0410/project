#include <sstream>
#include <iostream>
#include <stdlib.h>  
#include <stdio.h> 
#include <iomanip>
#include "graph.h"

int main(int argc, char* argv[]) {
    
   if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <graph_filename> <direction>" << std::endl;
        return 1;
    }

    std::string graphFilename = argv[1];
    std::string direction = argv[2];

    // Create an instance of the Graph class
    Graph* graph = new Graph();

    // Load the graph from the specified file
    if (!graph->loadGraph(graphFilename, direction)) {
        std::cout << "Failed to load the graph." << std::endl;
        delete graph;
        return 1;
    } else {
        graph->printAdjacencyLists();
    }

    std::string query;
    while (true) {
        // Read the next query from the user
        std::cin >> query;

        if (query == "find") {
            int source, destination, flag;
            // Read source, destination, and flag from user
            std::cin >> source >> destination >> flag;

            // Run Dijkstra's algorithm on the graph
            graph->runDijkstra(source, destination, flag);
        } else if (query == "write") {
            std::string action;
            int source, destination;
            // Read action, source, and destination from user
            std::cin >> action >> source >> destination;

            // Write the path based on the action
            graph->writePath(source, destination);
        } else if (query == "stop") {
            // Exit the program
            delete graph;
            return 0;
        } else {
            // Invalid query, print an error message
            std::cout << "Invalid query. Please use 'find', 'write', or 'stop'." << std::endl;
        }
    }
}
