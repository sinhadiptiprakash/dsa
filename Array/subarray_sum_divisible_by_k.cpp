#include <bits/stdc++.h>
using namespace std;
// approach is simple:
// reduce the problem to "count the subarrays with sum equal to 0 or k"
// to reduce this problem we will just use modulo operator to limit all cumulative sums from 0 to k
int subarraysDivByK(vector<int> &nums, int k)
{
    int idx = 0;
    // we will be storing the remainder and its occurence
    unordered_map<int, int> mp;
    // sum is for cumulative sum
    int sum = 0;
    // as we can always make 0 sum so make occurence of 0 sum is 1
    mp[0] = 1;
    int ans = 0;
    while (idx < nums.size())
    {
        sum += nums[idx];
        // get the remainder of sum upto this idx index
        int rem = sum % k;
        // we will always work with the positive remainders only so if there is a negative remainder
        // make it positive
        if (rem < 0)
        {
            rem = rem % k;
            rem += k;
        }
        // check if this remainder occurs previously or not
        // if so then add the occuerence to the ans and also update the occurence of the remainder
        if (mp.find(rem) != mp.end())
            ans += mp[rem];
        mp[rem]++;
        idx++;
    }
    return ans;
}
int main()
{
    return 0;
}