#include <bits/stdc++.h>
using namespace std;
vector<int> nonRepeating(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res;
    long long hash = 0;
    for (int i : nums)
        hash = hash ^ (1 << i);
    for (int i : nums)
    {
        if (hash & (1 << i))
            res.push_back(i);
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    auto res = nonRepeating(nums);
    if (res.size() >= 2)
        cout << res[0] << ' ' << res[1] << endl;
    return 0;
}