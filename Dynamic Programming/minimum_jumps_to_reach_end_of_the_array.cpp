#include <bits/stdc++.h>
using namespace std;
//using dp computing from right to left such that dp[i] stores the min jumps to reach end from i
int minJumps(int a[], int n)
{
    int dp[n];
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] == 0)
            dp[i] = INT_MAX;
        if (n - 1 - i <= a[i])
            dp[i] = 1;
        else
        {
            dp[i] = INT_MAX;
            for (int j = 1; j <= a[i] && j < n; j++)
                dp[i] = min(dp[i], dp[i + j]);
            if (dp[i] != INT_MAX)
                dp[i] += 1;
        }
    }
    return dp[0];
}
//using dp computing from left to right such that dp[i] stores the min jumps to reach i from 0
int minJumps2(int arr[], int n)
{
    // jumps[n-1] will hold the result
    int *jumps = new int[n];
    int i, j;

    if (n == 0 || arr[0] == 0)
        return INT_MAX;

    jumps[0] = 0;

    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}
// efficient GREEDY APPROACH this method is called ladder and stairs method
//very very important concept
//below is the O(N) time O(1) space implementation using a greedy approach
//here we are using ladder and stair approach:
//a ladder consists of stairs
//we iterate through the array of ladders and whenever we get a ladder greater than the maximuLadder so far we store it
//while the stairs of this stored maximumLadder is not finished climbing we still climbing i.e. decreasing the stairs
//whenever we finished climbing the curent maxLadder we start climbing the maximumLadder stored sofar
//this way we climb until we reach the end of the array
int minJumpsEfficient(int a[], int n)
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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << minJumpsEfficient(a, n) << endl;
    return 0;
}