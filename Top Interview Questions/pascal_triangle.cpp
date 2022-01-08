#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> res;
    for (int i = 0; i < numRows; i++)
    {
        if (i == 0)
        {
            res.push_back({1});
            continue;
        }
        vector<int> temp(i + 1);
        temp[0] = 1, temp[i] = 1;
        for (int j = 1; j < i; j++)
        {
            temp[j] = res.back()[j - 1] + res.back()[j];
        }
        res.push_back(temp);
    }
    return res;
}
int main()
{
    return 0;
}