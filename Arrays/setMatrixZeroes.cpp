class Solution
{
public:
    void setcol(vector<vector<int>> &matrix, int i, int j, int m, int n)
    {
        for (int k = 0; k < m; k++)
        {
            matrix[k][j] = 0;
        }
    }
    void setrow(vector<vector<int>> &matrix, int i, int j, int m, int n)
    {
        for (int k = 0; k < n; k++)
        {
            matrix[i][k] = 0;
        }
    }
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> temp(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    temp[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[i][j] == 0)
                {
                    setcol(matrix, i, j, m, n);
                    setrow(matrix, i, j, m, n);
                }
            }
        }
    }
};