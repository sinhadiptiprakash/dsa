#include <bits/stdc++.h>
using namespace std;
// We can observe that A wins game for n coins only when B loses for coins n-1 or n-x or n-y.
//recursive function to check wheather A wins the game or not based on the above observation
bool winner(int n, int x, int y)
{
    if (n == 0)
        return false;
    if (n == 1)
        return true;
    // If A losses any of i-1 or i-x or i-y game then A will definitely win game i
    // because i-1,i-x,i-y represents the winning strategy of A, i.e if at i-1, i-x, or i-y there is true
    // then that means A picks the last coin there, and if there is false then that means B picked the last coin
    // so if solution of i-1, i-x or i-y false then on those points B picked the last coin so its A's turn
    // as A is picking the curent coin A will win the game and if on those solutions a picked the last coin
    // its B's turn and B will win the game;
    bool res = 0;
    if (1 <= n)
        res |= !winner(n - 1, x, y);
    if (x <= n)
        res |= !winner(n - x, x, y);
    if (y <= n)
        res |= !winner(n - y, x, y);
    return res;
}
//using dp
bool winnerUsingDP(int n, int x, int y)
{
    bool dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (1 <= i)
            dp[i] |= !dp[i - 1];
        if (x <= i)
            dp[i] |= !dp[i - x];
        if (y <= i)
            dp[i] |= !dp[i - y];
    }
    return dp[n];
}
//basic recursion
bool winner(int n, int x, int y, bool turn)
{
    if (n == 0)
        return !turn;
    bool win = false;
    if (x <= n)
        win |= winner(n - x, x, y, !turn);
    if (y <= n)
        win |= winner(n - y, x, y, !turn);
    if (1 <= n)
        win |= winner(n - 1, x, y, !turn);
    return win;
}
int main()
{
    int x, y, n;
    cin >> n >> x >> y;
    if (winner(n, x, y, true))
        cout << 'A' << endl;
    else
        cout << 'B' << endl;
    return 0;
}