#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int a[],int n){
    int dp[n];
    for (int i = 0; i < n;i++){
        dp[i] = 1;
    }
    for (int i = 1; i < n;i++){
        for (int j = 0; j < i;j++){
            if(a[i]>a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int maxLen = 1;
    for (int i = 0; i < n; i++)
    {
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}// time O(N^2) space O(N)
// we can use LCS to solve this problem : first copy the array and sort the copied array in ascending 
// then find the LCS of this two arrays
//another approach using binary search
int longestSubsequence(int n, int arr[])
{
    vector<int> seq;
    seq.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > seq.back())
            seq.push_back(arr[i]);
        else
        {
            int index = lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
            seq[index] = arr[i];
        }
    }
    return seq.size();
}//time complexity O(N*log(N)) space complexity O(N)
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    cout << longestIncreasingSubsequence(a, n) << endl;
    return 0;
}