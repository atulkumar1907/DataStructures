#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;

void bfs(unordered_map<int, list<int>> adj, unordered_map<int, bool> &visited, vector<int> &ans, int i)
{
    queue<int> q;
    q.push(i);
    visited[i] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int n, unordered_map<int, list<int>> &adj)
{
    unordered_map<int, bool> visited;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bfs(adj, visited, ans, i);
        }
    }

    return ans;
}

void dfs(int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans)
{
    ans.push_back(parent);
    visited[parent] = 1;

    for (auto i : adj[parent])
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, ans);
        }
    }
}

vector<int> DFS(int n, int m, unordered_map<int, list<int>> &adj)
{
    unordered_map<int, bool> visited(false);
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // vector<int> component;
            dfs(i, adj, visited, ans);
            // ans.push_back(component);
        }
    }

    return ans;
}

int main()
{
    cout<<"Enter no. of nodes and Edges: ";
    int n, m;
    cin >> n >> m;

    unordered_map<int, list<int>> adj(n);

    cout<<"Enter edges: ";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Adjacency List
    cout<<"Adjacency List: "<<endl;
    for (auto i : adj)
    {
        cout << i.first << "->";
        for (auto j : i.second)
        {
            cout << j << ", ";
        }
        cout << endl;
    }

    vector<int> bfs = BFS(n, adj);
    vector<int> dfs = DFS(n, m, adj);

    // Breadth-First Search Traversal
    cout<<"BFS: ";
    for (auto i : bfs)
    {
        cout << i << " ";
    }
    cout << endl;

    // Depth-First Search Traversal
    cout<<"DFS: ";
    vector<int>::iterator it;
    for (auto i : dfs)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}