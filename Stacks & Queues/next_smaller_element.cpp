#include <bits/stdc++.h>
using namespace std;
// method is similar to the next greater element
vector<int> next_smaller(vector<int> nums)
{
    int n = nums.size();
    stack<int> stack;
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!stack.empty() && nums[i] < nums[stack.top()])
        {
            res[stack.top()] = nums[i];
            stack.pop();
        }
        stack.push(i);
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
    auto res = next_smaller(nums);
    for (auto i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}