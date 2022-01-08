#include <bits/stdc++.h>
using namespace std;
//uisng dynamic programming it similar to LIS
int maxProfit(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<vector<int>> jobs(n);
    for (int i = 0; i < n; i++)
        jobs[i] = {endTime[i], startTime[i], profit[i]};
    sort(jobs.begin(), jobs.end());
    vector<int> dp(n);
    dp[0] = jobs[0][2];
    for (int i = 1; i < n; i++)
    {
        dp[i] = jobs[i][2];
        for (int j = 0; j < i; j++)
        {
            if (jobs[j][0] <= jobs[i][1])
                dp[i] = max(dp[i], dp[j] + jobs[i][2]);
        }
    }
    int res = dp[0];
    for (int i = 1; i < n; i++)
        res = max(res, dp[i]);
    return res;
} // time complexity O(N^2) space O(N)
// we can optimize the above code using binary search in place of j loop
// below is the approach of DP+binary search
// Approach is simple: dp[i] will store the maximum profit by scheduling jobs[0....i]
// for filling dp[i] we find last scheduled job which has finish time<= start time of ith job
// we find the last scheduled job by using binary search to optimize the code
int binarySearch(vector<vector<int>> &jobs, vector<int> &job, int limit)
{
    int low = 0, high = limit - 1, mid;
    int res = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (jobs[mid][0] <= job[1])
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}
int maxProfitEfficient(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<vector<int>> jobs(n);
    for (int i = 0; i < n; i++)
        jobs[i] = {endTime[i], startTime[i], profit[i]};

    // sort the jobs according to the finish time
    sort(jobs.begin(), jobs.end());
    int dp[n];
    int lastScheduled, included;
    dp[0] = jobs[0][2];
    for (int i = 1; i < n; i++)
    {
        included = jobs[i][2];
        int lastScheduled = binarySearch(jobs, jobs[i], i);
        if (lastScheduled != -1)
            included += dp[lastScheduled];
        // maximum profit of scheduling jobs upto i, is either by including the curent job's profit or excluding
        dp[i] = max(dp[i - 1], included);
    }
    return dp[n - 1];
} //time complexity O(N*log(N)), space complexity O(N)
int main()
{
    int n;
    cin >> n;
    vector<int> startTime(n), endTime(n), profit(n);
    for (int i = 0; i < n; i++)
        cin >> startTime[i];
    for (int i = 0; i < n; i++)
        cin >> endTime[i];
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    cout << maxProfit(startTime, endTime, profit) << endl;
    return 0;
}