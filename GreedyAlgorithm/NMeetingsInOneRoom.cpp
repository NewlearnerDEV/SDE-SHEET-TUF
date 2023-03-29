class Solution
{
public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++)
        {
            vec.push_back(make_pair(end[i], start[i]));
        }
        sort(vec.begin(), vec.end());

        int cnt = 0;
        int x = 0;
        for (int i = 1; i < n; i++)
        {
            if (vec[x].first < vec[i].second)
            {
                cnt++;
                x = i;
            }
        }
        return cnt + 1;
    }
};
