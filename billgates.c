#include <stdio.h>
#include <cs50.h>

int find_shortest_path(int n, int source, int destination, int A[][n]);
int find_min(int dist[], bool visited[], int n);

int main() {
    int n;
    n = get_int();
    
    int A[n][n];
    
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            scanf("%d", &A[i][j]);
    
    int s, d;
    scanf("%d", &s);
    scanf("%d", &d);
    
    printf("%d\n", find_shortest_path(n, s, d, A));

    return 0;
}

// Uses Dijkstra's algorithm
int find_shortest_path(int n, int source, int destination, int A[][n]) 
{
    int dist[n]; // Stores distance between the source to all other elements
    bool visited[n]; // Stores status of each element, true = Element has been visited
    
    // Initialize distances to INT_MAX (Max value an int can store)
    for (int i=0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    
    // Distance from source to source is always 0
    dist[source] = 0;
    
    // Iterate over all the elements
    for(int i=0; i < n; i++) {
        // Find the element with the minium distance that has not been visited yet
        int u = find_min(dist, visited, n);
        visited[u] = true;
        
        for(int v=0; v < n; v++) {
            // checks if v is connected to u and it has not been visited
            if (A[u][v] != 0 && !visited[v]) {
                int t = (dist[u] != INT_MAX) ? dist[u] + 1 : 1; // prevents integer overflow
                if (t < dist[v]) // if the calculated distance between u and v is less than what we currently have then store the smaller distance
                    dist[v] = t;
            }
        }
    }
    
    // if dist[destination] is INT_MAX then there was no connection between source and destination so we return -1
    return (dist[destination] == INT_MAX) ? -1 : dist[destination];
}

int find_min(int dist[], bool visited[], int n)
{
    int min = INT_MAX;
    int idx = -1; // Idex of minimum value
    for(int i=0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}
