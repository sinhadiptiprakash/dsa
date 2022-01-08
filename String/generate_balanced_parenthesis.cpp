#include <bits/stdc++.h>
using namespace std;

//utility function
void Solve(int open, int close, string curr, int n, vector<string> &ans)
{
    if (curr.size() == 2 * n)
    {
        ans.push_back(curr);
        return;
    }
    if (open < n)
        Solve(open + 1, close, curr + "(", n, ans);
    if (close < open)
        Solve(open, close + 1, curr + ")", n, ans);
}
vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    Solve(0, 0, "", n, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    auto ans = generateParenthesis(n);
    for (auto s : ans)
        cout << s << endl;
    return 0;
}