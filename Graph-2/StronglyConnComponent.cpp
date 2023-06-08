
class Solution
{
    public :
        // Function to find number of strongly connected components in the graph.
        void dfs(int nd, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st){
            vis[nd] = 1;
for (auto itr : adj[nd])
{
    if (!vis[itr])
    {
        dfs(itr, vis, adj, st);
    }
}

st.push(nd);
}
void dfsn(int nd, vector<int> &vis, vector<int> adj[])
{
    vis[nd] = 1;
    for (auto itr : adj[nd])
    {
        if (!vis[itr])
        {
            dfsn(itr, vis, adj);
        }
    }
}
int kosaraju(int V, vector<vector<int>> &adj)
{
    // code here
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }
    vector<int> adjT[V];
    for (int i = 0; i < V; i++)

    {
        vis[i] = 0;
        for (auto itr : adj[i])
        {
            adjT[itr].push_back(i);
        }
    }
    int cnt = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cnt++;
            dfsn(node, vis, adjT);
        }
    }
    return cnt;
}
}
;