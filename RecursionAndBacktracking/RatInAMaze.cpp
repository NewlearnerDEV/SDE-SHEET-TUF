class Solution
{// checking lexicographically d,l,r,f..
//best ques
public:
    void maze(vector<vector<int>> &m, int x, int y, int n, vector<vector<int>> &vis, string temp, vector<string> &ans)
    {
        if (x == n - 1 && y == n - 1)
        {
            ans.push_back(temp);
            return;
        }

        if (x + 1 <= n - 1 && m[x + 1][y] == 1 && vis[x + 1][y] == 0)
        {
            vis[x][y] = 1;
            maze(m, x + 1, y, n, vis, temp + "D", ans);
            vis[x][y] = 0;
        }

        if (y - 1 >= 0 && m[x][y - 1] == 1 && vis[x][y - 1] == 0)
        {
            vis[x][y] = 1;
            maze(m, x, y - 1, n, vis, temp + "L", ans);
            vis[x][y] = 0;
        }

        if (y + 1 <= n - 1 && m[x][y + 1] == 1 && vis[x][y + 1] == 0)
        {
            vis[x][y] = 1;
            maze(m, x, y + 1, n, vis, temp + "R", ans);
            vis[x][y] = 0;
        }

        if (x - 1 >= 0 && m[x - 1][y] == 1 && vis[x - 1][y] == 0)
        {
            vis[x][y] = 1;
            maze(m, x - 1, y, n, vis, temp + "U", ans);
            vis[x][y] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (m[0][0] == 0)
        {
            ans.push_back("-1");
            return ans;
        }
        maze(m, 0, 0, n, vis, "", ans);
        return ans;
    }
};