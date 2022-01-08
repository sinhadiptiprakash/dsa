#include <bits/stdc++.h>
using namespace std;
void sum(vector<int> &candidates, int n, int target, vector<vector<int>> &res, vector<int> temp)
{
    if (target == 0)
    {
        res.push_back(temp);
        return;
    }
    if (n == 0)
        return;
    if (candidates[n - 1] <= target)
    {
        sum(candidates, n - 1, target, res, temp);
        temp.push_back(candidates[n - 1]);
        sum(candidates, n, target - candidates[n - 1], res, temp);
    }
    else
        sum(candidates, n - 1, target, res, temp);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    int n = candidates.size();
    sum(candidates, n, target, res, {});
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> candidates(n);
    for (int i = 0; i < n; i++)
        cin >> candidates[i];
    int target;
    cin >> target;
    auto res = combinationSum(candidates, target);
    for (auto v : res)
    {
        for (int i : v)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}