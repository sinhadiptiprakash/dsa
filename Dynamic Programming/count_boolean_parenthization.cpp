#include <bits/stdc++.h>
using namespace std;
int dp[201][201][2];
const int mod = 1e9 + 7;
//its a variation of MCM
//below is the RECURSIVE VERSION OF EVALUATE BOOLEAN EXPRESSION TO TRUE(BOOLEAN PARENTHIZATION)
int booleanParenthization(string s, int i, int j, bool isTrue)
{
    //if the string s is empty
    if (i > j)
        return 0;
    //if the size of the string is 1, then
    //if we are looking for true and that one character is true then return 1 else return 0
    if (i == j)
    {
        if (isTrue)
            return (s[i] == 'T' ? 1 : 0);
        else if (!isTrue)
            return (s[i] == 'F' ? 1 : 0);
    }
    int ans = 0;
    //for every operator postion we parentize the string and add all the ways
    for (int k = i + 1; k < j; k += 2)
    {
        int left_true, left_false, right_true, right_false;
        //counting the no. of ways to get true from k's left string
        left_true = booleanParenthization(s, i, k - 1, true);
        //counting the no. of ways to get false from k's left string
        left_false = booleanParenthization(s, i, k - 1, false);
        //counting the no. of ways to get true from k's right
        right_true = booleanParenthization(s, k + 1, j, true);
        //counting the no. of ways to get false from k's right
        right_false = booleanParenthization(s, k + 1, j, false);
        //if k-th operator is xor
        if (s[k] == '^')
        {
            //we can get true if t^f or f^t
            if (isTrue)
                ans += (left_true * right_false + left_false * right_true);
            //we can get false if t^t and f^f
            else
                ans += (left_true * right_true + left_false * right_false);
        }
        else if (s[k] == '|')
        {
            //we can get true if t|f or t|t f|t
            if (isTrue)
                ans += (left_true * right_false + left_true * right_true + left_false * right_true);
            //we can get false ibooleanf f|f
            else
                ans += (left_false * right_false);
        }
        else if (s[k] == '&')
        {
            //we get true if t&t
            if (isTrue)
                ans += (left_true * right_true);
            //we get false if t&f f&f f&t
            else
                ans += (left_true * right_false + left_false * right_true + left_false * right_false);
        }
    }
    return ans;
}
//below is the MEMOIZATION VERSION 1 USING 3D ARRAY
//as here in the funtion parameters 3 variables are changing so we need a 3D array
//we use dp3d[i][j][0] to store the no. of ways for false and dp3d[i][j][1] for storing no. of ways for true
int booleanParenthizationMemo1(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return (s[i] == 'T' ? 1 : 0);
        if (!isTrue)
            return (s[i] == 'F' ? 1 : 0);
    }
    if (dp[i][j][1] != -1 && isTrue)
        return dp[i][j][1];
    if (dp[i][j][0] != -1 && !isTrue)
        return dp[i][j][0];
    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lt, lf, rt, rf;
        lt = booleanParenthizationMemo1(s, i, k - 1, true);
        lf = booleanParenthizationMemo1(s, i, k - 1, false);
        rt = booleanParenthizationMemo1(s, k + 1, j, true);
        rf = booleanParenthizationMemo1(s, k + 1, j, false);
        if (s[k] == '^')
        {
            if (isTrue)
                ans += (lt * rf + lf * rt);
            else
                ans += (lt * rt + lf * rf);
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                ans += (lt * rf + lt * rt + lf * rt);
            else
                ans += (lf * rf);
        }
        else if (s[k] == '&')
        {
            if (isTrue)
                ans += (lt * rt);
            else
                ans += (lt * rf + lf * rt + lf * rf);
        }
    }
    if (isTrue)
        return dp[i][j][1] = ans % mod;
    return dp[i][j][0] = ans % mod;
}

int main()
{
    string expression;
    cin >> expression;
    int n = expression.length();
    memset(dp, -1, sizeof(dp));
    cout << booleanParenthizationMemo1(expression, 0, n - 1, 1) << endl;
    return 0;
}