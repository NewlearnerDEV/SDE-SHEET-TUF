vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    set<int> st;
    int y = -1;
    int n = A.size();
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        st.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!(st.find(i) != st.end()))
        {
            y = i;
            break; // finded missing
        }
    }
    int tot = n * (n + 1) / 2;
    int x = sum + y - tot;
    ans.push_back(x);
    ans.push_back(y);
    return ans;
}