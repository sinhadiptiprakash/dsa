#include <bits/stdc++.h>
using namespace std;
bool stack_permutations(vector<int> &pushed, vector<int> &popped)
{
    stack<int> stack;
    int popped_pointer = 0;
    for (int i = 0; i < pushed.size(); i++)
    {
        stack.push(pushed[i]);
        while (!stack.empty() && stack.top() == popped[popped_pointer])
        {
            stack.pop();
            popped_pointer++;
        }
    }
    return stack.empty();
}
int main()
{
    vector<int> pushed = {1, 2, 3, 4, 5}, popped = {4, 5, 3, 2, 1};
    cout << stack_permutations(pushed, popped) << endl;
    return 0;
}