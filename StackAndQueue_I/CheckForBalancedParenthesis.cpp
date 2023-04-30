class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push('(');
            }
            if (s[i] == '{')
            {
                st.push('{');
            }
            if (s[i] == '[')
            {
                st.push('[');
            }
            if (s[i] == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    return false;
                }
                st.pop();
            }
            if (s[i] == '}')
            {
                if (st.empty() || st.top() != '{')
                {
                    return false;
                }
                st.pop();
            }
            if (s[i] == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    return false;
                }
                st.pop();
            }
        }
        if (st.size() == 0)
        {
            return true;
        }
        return false;
    }
};