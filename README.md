# Directed Graph Cycle Detection Program

This program allows the user to detect cycles in a directed graph. It includes functionality to manage graph data dynamically and interactively. The program is designed to be executed from the command line with input and output handled through files.

## Features

The program includes the following capabilities:
- Add new vertices.
- Remove vertices.
- Add new edges.
- Remove edges.
- Edit edge weights.
- Detect cycles in a graph.
- Find the shortest or longest cyclic path based on edge weights.

## Input Format

Graph edges are provided in an input file in the following format:
```
1 -> 2 : 10,
2 -> 3 : 20,
3 -> 4 : 15,
3 -> 5 : 5,
1 -> 1 : 4,
```
## Usage

The program is executed from the command line with the following switches:
- `-i <input file>`: Specifies the input file containing the graph.
- `-o <output file>`: Specifies the output file to save the modified graph.
- `-c <cycle file>`: Specifies the output file to save detected cycles (each cycle is stored in a separate line, or a message is shown if no cycles exist in the graph).


## General Requirements

1. **Data Structures**: The implementation must be approved before use. The program operates using dynamic structures during runtime (e.g., no file-based structures during operations).
2. **File Handling**: Input and output are managed via files specified at runtime.
3. **Resilience**: The program is robust against minor format inconsistencies in the input data.
4. **Documentation**: All functions are documented using Doxygen.
5. **State Management**: Added or modified data is persistent across runs by appending changes to the data.


## How It Works

### Cycle Detection
The program identifies all cycles in the graph, considering dynamic graph updates (e.g., added/removed edges or vertices).

### Shortest/Longest Cyclic Path
The user can calculate the shortest or longest cyclic paths based on edge weights, depending on the requirement.

## Prerequisites

- C++ Compiler supporting C++11 or later.
- Command line tools for executing the program.

## License

Feel free to modify this template to include any additional features or specifications.

