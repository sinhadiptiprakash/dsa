#include <bits/stdc++.h>
using namespace std;
vector<int> dp;
//below is the memoized version of the solution using DP
int min_jumps_to_reach_the_end(int a[], int n)
{
    int dp[n];
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] == 0)
            dp[i] = INT_MAX;
        else if (i + a[i] >= n)
            dp[i] = 1;
        else
        {
            dp[i] = INT_MAX;
            for (int j = i + 1; j < n && j <= a[i] + i; j++)
                dp[i] = min(dp[i], dp[j]);
            if (dp[i] != INT_MAX)
                dp[i] += 1;
        }
    }
    return dp[0] == INT_MAX ? -1 : dp[0];
} //tike complexity is O(N*2) space complexity O(N) for dp table

//very very important concept
//below is the O(N) time O(1) space implementation using a greedy approach
//here we are using ladder and stair approach:
//a ladder consists of stairs
//we iterate through the array of ladders and whenever we get a ladder greater than the maximuLadder so far we store it
//while the stairs of this stored maximumLadder is not finished climbing we still climbing i.e. decreasing the stairs
//whenever we finished climbing the curent maxLadder we start climbing the maximumLadder stored sofar
//this way we climb until we reach the end of the array
int min_jumps_to_reach_the_end(int a[], int n)
{
    //if there is only one stair no jumps needed
    if (n <= 1)
        return 0;
    if (a[0] == 0)
        return -1;
    //at the first index we have the maximum ladder of a[0] stairs( base case)
    int maxLadder = a[0];
    //we have the a[0] no of the stairs of the maxLadder so far
    int stairs = a[0];
    //as we have to make at least one move we initialize jump to 1
    int jump = 1;
    //we start iterating from index 1 as we have already consider the cases for index 0
    for (int level = 1; level < n; level++)
    {
        //if we have reached the end of the array return the no. of jumps
        if (level == n - 1)
            return jump;
        //if the curent ladder size is greater than the maxLadder so far we update the maxLadder for further use
        maxLadder = max(maxLadder, level + a[level]);
        //as we are climbing one stair at a time in through the maxLadder until now we decerase stairs by one each time
        stairs--;
        //if the stairs become 0, then we have to choose the stairs of the next MaxLadder stored so far for climbing
        if (stairs == 0)
        {
            //as we are changing our ladder, that means we are making a jump
            jump++;
            //if the stairs in the maxLadder sofar is not enough to reach the curent level, that means we cant reach the end anyway
            if (maxLadder <= level)
                return -1;
            //after switching the ladder the no. of stairs we have is maxLadder-our curent level as we are switching
            //our ladder at curent level
            stairs = maxLadder - level;
        }
    }
    return -1;
}
int main()
{
    int a[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = sizeof(a) / sizeof(int);
    dp.resize(n, INT_MAX);
    int res = min_jumps_to_reach_the_end(a, n);
    cout << res << endl;
    return 0;
}