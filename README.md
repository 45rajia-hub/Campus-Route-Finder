# Campus Route Finder using Graphs in C

This project represents a college campus as an unweighted graph.
Each campus location is a vertex, and each direct walking route is an edge.

## Features

- Adjacency-list representation
- Adjacency-matrix representation
- BFS to find the route with minimum edges
- DFS traversal
- Reachability checking
- Connected-component detection
- Disconnected-location detection
- Interactive menu-driven program

## How to Compile

```bash
gcc campus_route_finder.c -o campus_route_finder
```

## How to Run

```bash
./campus_route_finder
```

## Sample BFS Input

```text
Enter source location: Main Gate
Enter destination location: Lab
```

## Sample BFS Output

```text
Shortest route: Main Gate -> Block 1 -> Block 2 -> Cafeteria -> Auditorium -> Lab
```

## Data Structures Used

- Array of location names
- Adjacency list using linked lists
- Adjacency matrix using a 2D array
- Queue for BFS
- Visited array
- Parent/predecessor array for route reconstruction
- Recursion for DFS
