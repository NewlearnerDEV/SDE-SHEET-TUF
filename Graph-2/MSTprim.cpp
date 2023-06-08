class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();
            int nd = itr.second;
            int wt = itr.first;
            if (vis[nd])
                continue;
            vis[nd] = 1;
            ans += wt;
            for (auto it : adj[nd])
            {
                int edge = it[1];
                int adjNd = it[0];
                if (!vis[adjNd])
                {
                    pq.push({edge, adjNd});
                }
            }
        }

        return ans;
    }
};