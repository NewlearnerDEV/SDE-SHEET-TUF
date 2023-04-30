#include <bits/stdc++.h>
void srt(stack<int> &stack, int num)
{
    if (stack.size() == 0 || (stack.size() != 0 && stack.top() < num))
    {
        stack.push(num);
        return;
    }
    int x = stack.top();
    stack.pop();
    srt(stack, num);
    stack.push(x);
}
void sortStack(stack<int> &stack)
{
    if (stack.size() == 0)
    {
        return;
    }
    int x = stack.top();
    stack.pop();
    sortStack(stack);
    srt(stack, num);
}