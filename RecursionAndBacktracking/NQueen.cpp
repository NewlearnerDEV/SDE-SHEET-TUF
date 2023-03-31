class Solution
{
public:
    int isSafe(int row, int col, int n, vector<string> li)
    {
        int temp1 = row;
        int temp2 = col;
        while (row >= 0 && col >= 0)
        {
            if (li[row][col] == 'Q')
            {
                return 0;
            }
            row--;
            col--;
        }
        row = temp1;
        col = temp2;
        while (row < n && col >= 0)
        {
            if (li[row][col] == 'Q')
            {
                return 0;
            }
            col--;
            row++;
        }
        row = temp1;
        col = temp2;
        while (col >= 0)
        {
            if (li[row][col] == 'Q')
            {
                return 0;
            }
            col--;
        }
        return 1;
    }
    void queenback(vector<vector<string>> &li, int col, int n, vector<string> &slot)
    {
        if (col == n)
        {
            li.push_back(slot);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, n, slot) == 1)
            {
                slot[row][col] = 'Q';

                queenback(li, col + 1, n, slot);
                slot[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> slot(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            slot[i] = s;
        }
        queenback(ans, 0, n, slot);
        return ans;
    }
};