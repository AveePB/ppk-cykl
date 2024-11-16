#pragma once
#ifndef GRAPH_EDITOR_H
#define GRAPH_EDITOR_H

#include <iostream>
#include "graphs.h"

namespace grapheditor {

    /**
     * @brief Adds a new vertex to the given graph.
     *
     * @param g The graph where the vertex will be added.
     */
    void addNewVertice(graphs::Graph& g);

    /**
     * @brief Removes an existing vertex from the given graph.
     *
     * @param g The graph from which the vertex will be removed.
     */
    void removeVertice(graphs::Graph& g);

    /**
     * @brief Adds a new edge between two vertices in the graph.
     *
     * @param g The graph where the edge will be added.
     */
    void addNewEdge(graphs::Graph& g);

    /**
     * @brief Removes an existing edge between two vertices in the graph.
     *
     * @param g The graph from which the edge will be removed.
     */
    void removeEdge(graphs::Graph& g);

    /**
     * @brief Updates the weight of an existing edge in the graph.
     *
     * @param g The graph containing the edge to be updated.
     */
    void updateEdgeWeight(graphs::Graph& g);
}
}

#endif