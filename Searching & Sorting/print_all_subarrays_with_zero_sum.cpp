#include <bits/stdc++.h>
using namespace std;
//brute force
int zero_sum_subarrays(int a[], int n)
{
    int cnt = 0;
    int sum;
    for (int i = 0; i < n; i++)
    {
        sum = a[i];
        if (sum == 0)
            cnt++;
        for (int j = i + 1; j < n; j++)
        {
            sum += a[j];
            if (sum == 0)
                cnt++;
        }
    }
    return cnt;
} //time complexity O(N^2)
//below is the approach using map
vector<pair<int, int>> zero_sum_subarrays_efficiet(int arr[], int n)
{
    // create an empty map
    unordered_map<int, vector<int>> map;

    // create an empty vector of pairs to store
    // subarray starting and ending index
    vector<pair<int, int>> out;

    // Maintains sum of elements so far
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        // add current element to sum
        sum += arr[i];

        // if sum is 0, we found a subarray starting
        // from index 0 and ending at index i
        if (sum == 0)
            out.push_back(make_pair(0, i));

        // If sum already exists in the map there exists
        // at-least one subarray ending at index i with
        // 0 sum
        if (map.find(sum) != map.end())
        {
            // map[sum] stores starting index of all subarrays
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        // Important - no else
        map[sum].push_back(i);
    }

    // return output vector
    return out;
}
// for counting only
int countSubarray(vector<int> arr, int n)
{
    // create an empty map
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp += arr[i];
        if (mp.find(temp) != mp.end())
        {
            sum += mp[temp];
            mp[temp]++;
        }
        else
        {
            mp[temp]++;
        }
    }
    return sum;
} //same time O(N) space O(N)
int main()
{
    int arr[] = {6, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr) / sizeof(int);
    auto res = zero_sum_subarrays_efficiet(arr, n);
    return 0;
}