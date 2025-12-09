#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>                             
#define MAX 20 
#define INF INT_MAX 
 
int cost[MAX][MAX]; // Cost matrix 
int n;              // Number of cities 
 
typedef struct { 
    int path[MAX]; // Path taken 
    int cost;      // Cost of the current path 
    int level;     // Level in the tree 
} Node; 
 
int min(int a, int b)  
 { 
    return (a < b) ? a : b; 
} 
 
// Function to create a new node 
Node* createNode(int path[], int level, int cost)  
 { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    int i; 
    for (i = 0; i < n; i++) 
        newNode->path[i] = path[i]; 
    newNode->level = level; 
    newNode->cost = cost; 
    return newNode; 
} 
// Function to perform Branch and Bound TSP 
void tsp() { 
    int minCost = INF,city,i; 
    Node* root = createNode((int[]){0}, 0, 0); // Starting from city 0 
    root->path[0] = 0; 
 
    Node* queue[MAX]; // Simple array to store nodes 
    int front = 0, rear = 0; 
 
    // Enqueue the root node 
    queue[rear++] = root; 
    while (front < rear) {
    	     Node* current = queue[front++]; 
 
        // If we have reached the last city 
        if (current->level == n - 1) { 
            // Check if we can return to the start 
            int finalCost = current->cost + cost[current->path[current->level]][0]; 
            minCost = min(minCost, finalCost); 
            free(current); 
            continue; 
        } 
        // Explore children nodes 
        for (city = 0; city < n; city++)  
{ 
            // Skip already visited cities 
            if (city == current->path[current->level] || city == 0) continue; 
 
            int newCost = current->cost + cost[current->path[current->level]][city]; 
            if (newCost < minCost) { // Only consider nodes that do not exceed the min cost found so far 
                int newPath[MAX]; 
                for ( i = 0; i <= current->level; i++) 
                    newPath[i] = current->path[i]; 
                newPath[current->level + 1] = city; 
 
                Node* child = createNode(newPath, current->level + 1, newCost); 
                queue[rear++] = child; 
            } 
        } 
            free(current); 
    } 
    printf("Minimum cost: %d\n", minCost); 
} 
int main() { 
 int i,j; 
    printf("Enter the number of cities: "); 
    scanf("%d", &n); 
 
    printf("Enter the cost matrix:\n"); 
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            scanf("%d", &cost[i][j]); 
    tsp(); 
    return 0; 
} 
 
 
 
 


