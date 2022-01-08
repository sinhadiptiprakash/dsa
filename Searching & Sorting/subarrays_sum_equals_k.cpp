#include <bits/stdc++.h>
using namespace std;
//brute force approach
int subarray_sum_equals_k(vector<int> &a, int k)
{
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            //we are now calculating the sum of the subarray i to j
            int sum = 0;
            for (int l = i; l <= j; l++)
            {
                sum += a[l];
            }
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
} //time complexity O(N^3) space complexity O(1)
//using cummulative sum we can eliminate the inner l loop
int subarray_sum_equals_k_2(vector<int> &a, int k)
{
    int cnt = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
} //time complexity O(N^2) space complexity O(1)
//below is the map based approach
/*
The idea behind this approach is as follows:
 If the cumulative sum(represented by sum[i] for sum up to i th index) up to two indices is the same,
 the sum of the elements lying in between those indices is zero. 
 See the problem "check if there is subarrya with 0 sum" to understand the above idea
 Extending the same thought further, if the cumulative sum up to two indices, 
 say i and j is at a difference of kk i.e. if sum[i] - sum[j] = k,
 the sum of elements lying between indices i and j is k

Based on these thoughts, we make use of a hashmap mapmap which is used to store the cumulative sum 
up to all the indices possible along with the number of times the same sum occurs. 
We store the data in the form: (sum_i, no. of occurrences of sum_i)
We traverse over the array numsnums and keep on finding the cumulative sum. 
Every time we encounter a new sum, we make a new entry in the hashmap corresponding to that sum. 
If the same sum occurs again, we increment the count corresponding to that sum in the hashmap. 
Further, for every sum encountered, we also determine the number of times the sum sum-ksum−k has occurred already, 
since it will determine the number of times a subarray with sum kk has occurred up to the current index. 
We increment the countcount by the same amount.
*/
int subarray_sum_equals_k_efficient(vector<int> &a, int k)
{
    int n = a.size();
    int cnt = 0, sum = 0;
    unordered_map<int, int> map;
    //first we are pushing 0 sum in map with occurence 1 which means 0 sum always exists 1 times before any operation
    map[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        //if we get the sum-k in map
        //it means that upto this index we have the subarrays one with sum sum-k and another with sum k
        //so we should increase the count by map[sum-k]
        if (map.find(sum - k) != map.end())
        {
            cnt += map[sum - k];
        }
        //we always store the sum with its occurence in map
        map[sum]++;
    }
    return cnt;
} //time complexity O(N) space complexity O(N)
int main()
{
    vector<int> a = {2, 1, 1};
    cout << subarray_sum_equals_k_2(a, 2) << endl;
    return 0;
}