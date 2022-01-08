#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string str)
{
    int n = str.length();
    int maxLen = 1;
    int startingIndex;
    int low, high;
    //one by one choose a character as a center character and calculate the even and odd length palindromes around it
    for (int i = 1; i < n; i++)
    {
        //first compute even length palindrom
        low = i - 1, high = i;
        while (low >= 0 && high < n && str[low] == str[high])
        {
            if (maxLen > high - low + 1)
            {
                maxLen = high - low + 1;
                startingIndex = low;
            }
            low--;
            high++;
        }
        // now compute odd length palindrome around this very character
        low = i - 1, high = i + 1;
        while (low >= 0 && high < n && str[low] == str[high])
        {
            if (maxLen > high - low + 1)
            {
                maxLen = high - low + 1;
                startingIndex = low;
                low--;
                high++;
            }
        }
        string res = "";
        for (int i = startingIndex; i < startingIndex + maxLen; i++)
            res.push_back(str[i]);
        return res;
    }
}
int main()
{
    return 0;
}