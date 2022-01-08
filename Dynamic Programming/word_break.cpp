#include <bits/stdc++.h>
using namespace std;
//bottom up dp
bool wordBreak(string str, vector<string> &dict)
{
    unordered_set<string> dictionary(dict.begin(), dict.end());
    int n = str.length();
    bool dp[n + 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j])
            {
                string temp = str.substr(j, i - j);
                if (dictionary.find(temp) != dictionary.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    string str;
    cin >> str;
    cout << wordBreak(str, dict) << endl;
    return 0;
}