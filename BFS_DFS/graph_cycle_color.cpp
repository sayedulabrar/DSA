// A C++ program to implement greedy algorithm for graph coloring
#include <iostream>
#include <list>
using namespace std;





bool hasCycleBFS(int start) {
    vector<bool> visited(V, false); // Mark all vertices as not visited
    vector<int> parent(V, -1); // Store the parent of each vertex during BFS
    queue<int> q;
    q.push(start); // Enqueue the start vertex
    visited[start] = true; // Mark start vertex as visited

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Visit all adjacent vertices of u
        for (int v : adj[u]) {
            // If v is not visited, mark it as visited and enqueue it
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u; // Set u as parent of v
                q.push(v);
            }
            // If v is visited and it's not the parent of u, there is a cycle
            else if (parent[u] != v) {
                return true; // Cycle detected
            }
        }
    }
    return false; // No cycle found
}

// A class that represents an undirected graph
class Graph
{
	int V; // No. of vertices
	list<int> *adj; // A dynamic array of adjacency lists
public:
	// Constructor and destructor
	Graph(int V) { this->V = V; adj = new list<int>[V]; }
	~Graph()	 { delete [] adj; }

	// function to add an edge to graph
	void addEdge(int v, int w);

	// Prints greedy coloring of the vertices
	void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v); // Note: the graph is undirected
}

// Assigns colors (starting from 0) to all vertices and prints
// the assignment of colors
void Graph::greedyColoring()
{
	int result[V];

	// Initialize remaining V-1 vertices as unassigned
	for (int u = 1; u < V; u++)
		result[u] = -1; // no color is assigned to u

	// Assign the first color to first vertex
	result[0] = 0;

	bool available[V];

	// Assign colors to remaining V-1 vertices
	for (int u = 1; u < V; u++)
	{

		for (int cr = 0; cr < V; cr++) available[cr] = true;

		for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
			if (result[i] != -1)
				available[result[i]] = false;

		// Find the first available color
		int cr;
		for (cr = 0; cr < V; cr++)
			if (available[cr] == true)
				break;

		result[u] = cr; // Assign the found color

	}

	// print the result
	for (int u = 0; u < V; u++)
		cout << "Vertex " << u << " ---> Color "
			<< result[u] << endl;
}

// Driver program to test above function
int main()
{
	Graph g1(5);
	g1.addEdge(0, 1);
	g1.addEdge(0, 2);
	g1.addEdge(1, 2);
	g1.addEdge(1, 3);
	g1.addEdge(2, 3);
	g1.addEdge(3, 4);
	cout << "Coloring of graph 1 \n";
	g1.greedyColoring();

	Graph g2(5);
	g2.addEdge(0, 1);
	g2.addEdge(0, 2);
	g2.addEdge(1, 2);
	g2.addEdge(1, 4);
	g2.addEdge(2, 4);
	g2.addEdge(4, 3);
	cout << "\nColoring of graph 2 \n";
	g2.greedyColoring();

	return 0;
}





