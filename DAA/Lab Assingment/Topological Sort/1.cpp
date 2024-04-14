#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> inDegree(V, 0);
    vector<int> topoOrder;
    queue<int> q;

    // Calculate in-degree for each vertex
    for(int u=0; u<V; u++) 
    {
        for(int j=0; j<adj[u].size(); j++) 
        {
            int v = adj[u][j];
            inDegree[v]++;
        }
    }

    // Add all vertices with in-degree 0 to queue
    for(int i=0; i<V; i++) 
    {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Perform topological sort
    while(!q.empty()) 
    {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for(int j=0; j<adj[u].size(); j++) 
        {
            int v = adj[u][j];
            if(--inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topoOrder;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[V];
    for (int i = 0; i < E; i++) {
        int u, v;
        cout << "Enter the vertices of edge " << i + 1 << ": ";
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> topoOrder = topoSort(V, adj);

    cout << "Topological sort order: ";
    for(int i=0; i<topoOrder.size(); i++) {
        cout << topoOrder[i] << " ";
    }
    cout << endl;

    return 0;
}
