
#include <stdio.h>
#include <stdlib.h>

#define V 9

char *places[V] = {
    "Main Gate", "Library", "Block 1",
    "Block 2", "Cafeteria", "Auditorium",
    "Parking", "Lab", "Sports Ground"
};

struct Node {
    int vertex;
    struct Node *next;
};

struct Node *graph[V];

// Create a new adjacency-list node
struct Node *createNode(int v) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add an undirected edge
void addEdge(int u, int v) {
    struct Node *node = createNode(v);
    node->next = graph[u];
    graph[u] = node;

    node = createNode(u);
    node->next = graph[v];
    graph[v] = node;
}

// Initialize campus graph
void initializeGraph() {
    for (int i = 0; i < V; i++)
        graph[i] = NULL;

    addEdge(0, 1);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(3, 4);
    addEdge(3, 6);
    addEdge(4, 5);
    addEdge(4, 7);
    addEdge(5, 7);
}

// Display all campus locations
void displayLocations() {
    printf("\n--- Campus Locations ---\n");
    for (int i = 0; i < V; i++)
        printf("%d. %s\n", i, places[i]);
}

// Display adjacency list
void displayGraph() {
    printf("\n--- Adjacency List ---\n");

    for (int i = 0; i < V; i++) {
        printf("%s: ", places[i]);

        struct Node *temp = graph[i];
        while (temp != NULL) {
            printf("%s -> ", places[temp->vertex]);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// BFS shortest route
void BFS(int start, int destination) {
    int visited[V] = {0};
    int parent[V];
    int queue[V];
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++)
        parent[i] = -1;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        struct Node *temp = graph[current];

        while (temp != NULL) {
            int next = temp->vertex;

            if (!visited[next]) {
                visited[next] = 1;
                parent[next] = current;
                queue[rear++] = next;
            }
            temp = temp->next;
        }
    }

    if (!visited[destination]) {
        printf("\nNo route exists between %s and %s.\n",
               places[start], places[destination]);
        return;
    }

    int path[V];
    int count = 0;

    for (int v = destination; v != -1; v = parent[v])
        path[count++] = v;

    printf("\nShortest Route (BFS):\n");

    for (int i = count - 1; i >= 0; i--) {
        printf("%s", places[path[i]]);
        if (i > 0)
            printf(" -> ");
    }

    printf("\nMinimum edges: %d\n", count - 1);
}

// DFS recursive traversal
void DFS(int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%s -> ", places[vertex]);

    struct Node *temp = graph[vertex];

    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFS(temp->vertex, visited);

        temp = temp->next;
    }
}

// Show reachable and unreachable locations
void showReachable(int start) {
    int visited[V] = {0};
    int queue[V];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];

        struct Node *temp = graph[current];

        while (temp != NULL) {
            int next = temp->vertex;

            if (!visited[next]) {
                visited[next] = 1;
                queue[rear++] = next;
            }
            temp = temp->next;
        }
    }

    printf("\nReachable Locations:\n");
    for (int i = 0; i < V; i++)
        if (visited[i])
            printf("%s\n", places[i]);

    printf("\nUnreachable Locations:\n");
    int found = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            printf("%s\n", places[i]);
            found = 1;
        }
    }

    if (!found)
        printf("None\n");
}

int main() {
    int choice, start, destination;
    int visited[V];

    initializeGraph();

    while (1) {
        printf("\n===== CAMPUS ROUTE FINDER =====\n");
        printf("1. Display Campus Locations\n");
        printf("2. Display Graph\n");
        printf("3. Find Shortest Route (BFS)\n");
        printf("4. DFS Traversal\n");
        printf("5. Show Reachable Locations\n");
        printf("6. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        if (choice == 6) {
            printf("Thank you!\n");
            break;
        }

        if (choice == 1) {
            displayLocations();
        }
        else if (choice == 2) {
            displayGraph();
        }
        else if (choice == 3) {
            displayLocations();

            printf("Enter source: ");
            if (scanf("%d", &start) != 1) break;

            printf("Enter destination: ");
            if (scanf("%d", &destination) != 1) break;

            if (start >= 0 && start < V &&
                destination >= 0 && destination < V)
                BFS(start, destination);
            else
                printf("Invalid location!\n");
        }
        else if (choice == 4) {
            displayLocations();

            printf("Enter starting location: ");
            if (scanf("%d", &start) != 1) break;

            if (start >= 0 && start < V) {
                for (int i = 0; i < V; i++)
                    visited[i] = 0;

                printf("\nDFS Traversal:\n");
                DFS(start, visited);
                printf("END\n");
            }
            else
                printf("Invalid location!\n");
        }
        else if (choice == 5) {
            displayLocations();

            printf("Enter starting location: ");
            if (scanf("%d", &start) != 1) break;

            if (start >= 0 && start < V)
                showReachable(start);
            else
                printf("Invalid location!\n");
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    // Free dynamically allocated graph nodes
    for (int i = 0; i < V; i++) {
        struct Node *temp = graph[i];
        while (temp != NULL) {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }

    return 0;
}
