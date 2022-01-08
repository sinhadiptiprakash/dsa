#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void permute(vector<int> &nums, int index, int n)
{
    if (index == n)
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < n; i++)
    {
        swap(nums[i], nums[index]);
        permute(nums, index + 1, n);
        swap(nums[i], nums[index]);
    }
}
vector<vector<int>> permutation(vector<int> &nums)
{
    int n = nums.size();
    permute(nums, 0, n);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    auto ans = permutation(nums);
    for (auto v : ans)
    {
        for (auto i : v)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}