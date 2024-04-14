#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int u, vector<vector<int> >& adj, vector<bool>& visited, stack<int>& s) 
{
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) 
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            dfs(v, adj, visited, s);
        }
    }
    s.push(u);
}

void topologicalSort(vector<vector<int> >& adj, int n) 
{
    vector<bool> visited(n, false);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i]) 
        {
            dfs(i, adj, visited, s);
        }
    }
    while (!s.empty()) 
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int> > adj(n);
    int m;
    cout << "Enter the number of edges: ";
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "Enter an edge (u v): ";
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << "Following is a Topological Sort of the given graph \n";
    topologicalSort(adj, n);
    return 0;
}

// adj[5].push_back(2);
    // adj[5].push_back(0);
    // adj[4].push_back(0);
    // adj[3].push_back(1);
    // adj[2].push_back(3);
    // adj[3].push_back(1)