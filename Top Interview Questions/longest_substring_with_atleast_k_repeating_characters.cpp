#include <bits/stdc++.h>
using namespace std;
// brute force approach
bool isValid(string s, int start, int end, int k, int countMap[26])
{
    int countLetters = 0, countAtLeastK = 0;
    for (int i = 0; i < 26; i++)
    {
        if (countMap[i] > 0)
            countLetters++;
        if (countMap[i] >= k)
            countAtLeastK++;
    }
    return countAtLeastK == countLetters;
}
int longestSubstring(string s, int k)
{
    if (s.size() == 0 || k > s.length())
    {
        return 0;
    }
    int countMap[26] = {0};
    int n = s.length();
    int result = 0;
    for (int start = 0; start < n; start++)
    {
        // reset the count map
        memset(countMap, 0, sizeof(countMap));
        for (int end = start; end < n; end++)
        {
            countMap[s[end] - 'a']++;
            if (isValid(s, start, end, k, countMap))
            {
                result = max(result, end - start + 1);
            }
        }
    }
    return result;
}
// by sliding window technique
// get the maximum number of unique letters in the string s
int getMaxUniqueLetters(string s)
{
    bool map[26] = {0};
    int maxUnique = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (!map[s[i] - 'a'])
        {
            maxUnique++;
            map[s[i] - 'a'] = true;
        }
    }
    return maxUnique;
}
int longestSubstring(string s, int k)
{
    int countMap[26];
    int maxUnique = getMaxUniqueLetters(s);
    int result = 0;
    for (int currUnique = 1; currUnique <= maxUnique; currUnique++)
    {
        // reset countMap
        memset(countMap, 0, sizeof(countMap));
        int windowStart = 0, windowEnd = 0, idx = 0, unique = 0, countAtLeastK = 0;
        while (windowEnd < s.size())
        {
            // expand the sliding window
            if (unique <= currUnique)
            {
                idx = s[windowEnd] - 'a';
                if (countMap[idx] == 0)
                    unique++;
                countMap[idx]++;
                if (countMap[idx] == k)
                    countAtLeastK++;
                windowEnd++;
            }
            // shrink the sliding window
            else
            {
                idx = s[windowStart] - 'a';
                if (countMap[idx] == k)
                    countAtLeastK--;
                countMap[idx]--;
                if (countMap[idx] == 0)
                    unique--;
                windowStart++;
            }
            if (unique == currUnique && unique == countAtLeastK)
                result = max(windowEnd - windowStart, result);
        }
    }
    return result;
}
int main()
{
    return 0;
}