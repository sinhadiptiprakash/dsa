#include <bits/stdc++.h>
using namespace std;
bool isPal(string &s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}
void dfs(string &s, int i, int n, vector<string> temp, vector<vector<string>> &res)
{
    if (i == n)
    {
        res.push_back(temp);
        return;
    }
    string str = "";
    for (int j = i; j < n; j++)
    {
        str.push_back(s[j]);
        if (isPal(str))
        {
            temp.push_back(str);
            dfs(s, j + 1, n, temp, res);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> temp;
    int n = s.size();
    dfs(s, 0, n, temp, res);
    return res;
}
int main()
{
    string s;
    cin >> s;
    auto res = partition(s);
    for (auto v : res)
    {
        for (auto str : v)
            cout << str << ' ';
        cout << endl;
    }
    return 0;
}