class DSU
{
    vector<int> rank;
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findPar(int i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        return parent[i] = findPar(parent[i]);
    }
    void unionByRank(int u, int v)
    {
        int par_u = findPar(u);
        int par_v = findPar(v);
        if (rank[par_u] < rank[par_v])
        {
            parent[par_u] = par_v;
        }
        else if (rank[par_v] < rank[par_u])
        {
            parent[par_v] = par_u;
        }
        else
        {
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int par_u = findPar(u);
        int par_v = findPar(v);
        if (par_u == par_v)
        {
            return;
        }
        if (size[par_u] < size[par_v])
        {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
        else
        {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        DSU ds(V);
        vector<pair<int, pair<int, int>>> vec;
        for (int i = 0; i < V; i++)
        {
            for (auto itr : adj[i])
            {
                vec.push_back({itr[1], {i, itr[0]}});
            }
        }
        sort(vec.begin(), vec.end());
        int ans = 0;
        for (auto itr : vec)
        {
            if (ds.findPar(itr.second.first) != ds.findPar(itr.second.second))
            {
                ans = ans + itr.first;
                ds.unionByRank(itr.second.first, itr.second.second);
            }
        }
        return ans;
    }
};