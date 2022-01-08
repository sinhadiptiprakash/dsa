#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    vector<int> freq(256, 0);
    int i = 0, start = 0;
    int n = s.length();
    int maxLen = 0;
    while (i < n)
    {
        if (!freq[s[i]])
        {
            freq[s[i]]++;
            maxLen = max(maxLen, i - start + 1);
            i++;
        }
        else
        {
            while (freq[s[i]])
            {
                freq[s[start]]--;
                start++;
            }
        }
    }
    return maxLen;
}
int main()
{
    return 0;
}