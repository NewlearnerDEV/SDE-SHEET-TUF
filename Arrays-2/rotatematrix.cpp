class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int up = 0;
        int down = n - 1;
        while (up < down)
        {

            matrix[up].swap(matrix[down]);
            up++;
            down--;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};