#include <bits/stdc++.h>
using namespace std;
/*
Since the difference between the heights of left and right subtree is not more than one, 
possible heights of left and right part can be one of the following: 
 
1. (h-1), (h-2) //1
2. (h-2), (h-1) //-1
3. (h-1), (h-1) //0
 
count(h) = count(h-1) * count(h-2) + 
           count(h-2) * count(h-1) + 
           count(h-1) * count(h-1)
        = 2 * count(h-1) * count(h-2) +  
          count(h-1) * count(h-1)
       = count(h-1) * (2*count(h - 2) + 
                          count(h - 1))
Hence we can see that the problem has optimal substructure property.
A recursive function to count no of balanced binary trees of height h is: 
*/
int countBBT(int h)
{
    // One tree is possible with height 0 or 1
    if (h == 0 || h == 1)
        return 1;
    return countBBT(h - 1) * (2 * countBBT(h - 2) + countBBT(h - 1));
}
long long int countBBTDP(int h)
{
    long long int dp[h + 1];
    const int mod = 1e9 + 7;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= h; i++)
    {
        dp[i] = (dp[i - 1] * ((2 * dp[i - 2]) + dp[i - 1]));
    }
    return dp[h];
}
int main()
{
    int h;
    cin >> h;
    cout << countBBTDP(h) << endl;
    return 0;
}