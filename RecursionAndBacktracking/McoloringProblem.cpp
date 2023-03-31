class Solution
public:
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool ok(bool graph[101][101], int ind, int i, int n, vector<int> color)
{
    for (int j = 0; j < n; j++)
    {
        if (graph[j][ind] == 1 && color[j] == i)
        {
            return false;
        }
    }
    return true;
}
bool mcolor(bool graph[101][101], int m, int ind, int n, vector<int> &color)
{
    if (ind == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (ok(graph, ind, i, n, color) == true)
        {
            color[ind] = i;
            if (mcolor(graph, m, ind + 1, n, color) == true)
            {
                return true;
            }
            color[ind] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n + 1, 0);
    bool ans = mcolor(graph, m, 0, n, color);

    return ans;
}
}
;