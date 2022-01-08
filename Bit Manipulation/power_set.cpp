#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> powerSet(int a[], int n)
{
    vector<vector<int>> res;
    //for storing the curent subset
    vector<int> cur;
    int x;
    //by the help of bit manipulation we are traversing from 0 to 2^N as mask<(1<<n)=2^N
    for (unsigned int mask = 0; mask < (1 << n); mask++)
    {
        //at first we clear the result vector to store the curent subset
        cur.clear();
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                cur.push_back(a[i]);
        }
        res.push_back(cur);
    }
    return res;
}
// generating k-size subarrays
vector<vector<int>> powerSetOfSizeK(int a[], int n, int k)
{
    vector<vector<int>> res;
    //for storing the curent subset
    vector<int> cur;
    int x;
    //by the help of bit manipulation we are traversing from 0 to 2^N as mask<(1<<n)=2^N
    for (unsigned int mask = 0; mask < (1 << n); mask++)
    {
        //at first we clear the result vector to store the curent subset
        cur.clear();
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
                cur.push_back(a[i]);
        }
        // now restrict the size of the subset to be pushed to the resultant vector
        if (cur.size() == k)
            res.push_back(cur);
    }
    return res;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    auto res = powerSetOfSizeK(a, 5, 3);
    for (auto v : res)
    {
        for (auto i : v)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}