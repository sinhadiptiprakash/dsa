#include <bits/stdc++.h>
using namespace std;
bool isAnagram(vector<int> &check, vector<int> &pat)
{
    for (int i = 0; i < 26; i++)
    {
        if (pat[i] != check[i])
            return false;
    }
    return true;
}
vector<int> findAnagrams(string s, string p)
{
    vector<int> pat(26, 0);
    vector<int> check(26, 0);
    vector<int> res;
    for (char c : p)
        pat[c - 'a']++;
    int pLen = p.length(), sLen = s.length();
    int start = 0, end = 0;
    while (end < pLen && end < sLen)
    {
        check[s[end++] - 'a']++;
    }
    while (end < sLen)
    {
        if (isAnagram(pat, check))
            res.push_back(start);
        check[s[start++] - 'a']--;
        check[s[end++] - 'a']++;
    }
    if (isAnagram(pat, check))
        res.push_back(start);
    return res;
}
int main()
{
    return 0;
}