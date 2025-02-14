# The Lost Woods

## Introduction

This project compares the performance of the **Dijkstra** and **A*** algorithms in a graph traversal scenario. The graph includes vertices with coordinates, trails with Euclidean distances, and portals that act as zero-distance paths. The A* algorithm uses the Euclidean distance as its heuristic function. The goal is to find the shortest path from a starting vertex to a destination vertex while considering a limited energy budget and a maximum number of usable portals.

## Features

- **Graph Representation**: The graph can be represented using either an adjacency list or an adjacency matrix.
- **Portals**: Special edges that allow instant travel between two vertices (zero distance).
- **Energy Constraint**: The total energy available limits the distance that can be traveled.
- **Heuristic Function**: The A* algorithm uses the Euclidean distance as a heuristic to guide the search.
- **Performance Metrics**: The program measures the execution time and path length for both Dijkstra and A* algorithms.

## Prerequisites

### Compiler
- **C++ Compiler** (e.g., `g++`)

### Dependencies
- **C++ Standard Library** (No external dependencies required)

## How to Compile and Run

### Using Makefile

The project includes a `Makefile` to simplify the compilation process. Below are the available commands:

1. **Compile the Program**:  
To compile the program, run:
```bash
make
```

This will generate the executable in the ./bin/ folder.

2. **Clean Build Files**:
To remove all compiled object files and the executable, run:

```bash
make clean
```

3. **Compile with Specific Test Flags**:
The Makefile supports different test modes. You can compile the program with specific test flags using the TEST variable:

For testing algorithms (TEST_ALGS):
```bash
make all TEST=algs
```

For testing adjacency list space (TEST_LIST_SPACE):
```bash
make all TEST=list-space
```

For testing adjacency matrix space (TEST_MATRIZ_SPACE):
```bash
make all TEST=matriz-space
```

### Execution

After compiling, run the program using:
```bash
./bin/a.out < input_file.txt
```

## Input File Format

### First Line
- **n**: Number of vertices.  
- **m**: Number of trails.  
- **k**: Number of portals.  
- **dijkOrAstar** (Optional): Test mode:  
  - `0` for none  
  - `1` for Dijkstra  
  - `2` for A*  

### Next `n` Lines
Each line contains the **x** and **y** coordinates of a vertex.  

### Next `m` Lines
Each line contains two integers representing the **start** and **end** vertices of a trail.  

### Next `k` Lines
Each line contains two integers representing the **start** and **end** vertices of a portal.  

### Last Line
- **s**: The amount of energy available.  
- **q**: The maximum number of usable portals.  


## Program Output

The output of the program depends on the compilation type.
