#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
//recursive
int eggDrop(int egg, int flr)
{
    //base case:1. if there are no floor or 1 floor only then we need only the no. of floor eggs to test
    if (flr == 0 || flr == 1)
        return flr;
    //base case 2: if we have 1 egg only,then in the worst case we have to check every single floor
    if (egg == 1)
        return flr;
    int temp, mn = INT_MAX;
    //we are checking every floor between 1 and flr
    for (int k = 1; k <= flr; k++)
    {
        //at every floor we have 2 choices:
        //1. egg breaks at this floor
        //2. egg does'nt berak
        //if the egg breaks then no .of floor would be k-1,
        //because as at this floor egg breaks we should go down
        //because at floors abaove k eggs are breakable and no. of eggs would be egg-1
        //if egg does'nt break then no. of floor would be k-1
        // because at flooors below k eggs are unbreakable, so we should  go up
        //here we choose the max of two choices results becaus we have to get the result in WORST CASE
        //we are adding 1 to the outcome of max of two choices because we are considering the curent Drop
        temp = 1 + max(eggDrop(egg - 1, k - 1), eggDrop(egg, flr - k));
        //here we use the min. function bcz we need to calculate the min. no of drops
        mn = (temp < mn ? temp : mn);
    }
    return mn;
}
//below is the MEMOIZATION VERSION OF EGG DROPPIG PUZZLE
int eggDropMemo(int egg, int flr)
{
    if (flr == 1 || flr == 0)
        return flr;
    if (egg == 1)
        return flr;
    //if we have solved the curent sub-problem then return the result
    if (dp[egg][flr] != -1)
        return dp[egg][flr];
    int temp, mn = INT_MAX;
    for (int k = 1; k <= flr; k++)
    {
        temp = 1 + max(eggDropMemo(egg - 1, k - 1), eggDropMemo(egg, flr - k));
        mn = min(mn, temp);
    }
    return dp[egg][flr] = mn;
}
int eggDropBU(int egg, int flr)
{
    int dp[egg + 1][flr + 1];
    for (int i = 1; i <= egg; i++)
    {
        for (int j = 0; j <= flr; j++)
        {
            if (i == 1 || i == 0)
                dp[i][j] = j;
            else if (j == 0 || j == 1)
                dp[i][j] = j;
        }
    }
    int temp;
    for (int i = 2; i <= egg; i++)
    {
        for (int j = 2; j <= flr; j++)
        {
            dp[i][j] = INT_MAX;
            for (int k = 1; k <= flr; k++)
            {
                temp = 1 + max(dp[i - 1][k - 1], dp[i][j - k]);
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }
    return dp[egg][flr];
}
int main()
{
    int eggs, floors;
    cin >> eggs >> floors;
    cout << eggDropBU(eggs, floors) << endl;
    return 0;
}