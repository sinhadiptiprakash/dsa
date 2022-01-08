#include <bits/stdc++.h>
using namespace std;
int firstUniqChar(string s)
{
    int len = s.length();
    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'a']++;
    }
    for (int i = 0; i < len; i++)
    {
        if (freq[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}
int main()
{
    return 0;
}