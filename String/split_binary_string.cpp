#include <bits/stdc++.h>
using namespace std;
int split_binary_string_with_equal_one_zero(string str)
{
    int zeros = 0, ones = 0;
    int res = 0;
    for (char c : str)
    {
        if (c == '0')
            zeros++;
        else
            ones++;
        if (zeros == ones)
        {
            res++;
            zeros = 0;
            ones = 0;
        }
    }
    if (res == 0)
        res = -1;
    return res;
} //time complexity O(N) space complexity O(1)
int main()
{
    string str;
    cin >> str;
    cout << split_binary_string_with_equal_one_zero(str) << endl;
    return 0;
}