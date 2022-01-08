//Longest Substring without Repeating Characters
#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> map;
    int len = 0;
    int ans = 0;
    int start = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (map.count(s[i]))
        {
            while (s[start] != s[i] && start < i)
            {
                map.erase(s[start]);
                start++;
            }

            start++;
            len = i - start + 1;
            ans = max(len, ans);
        }
        else
        {
            len++;
            ans = max(len, ans);
            map[s[i]]++;
        }
    }

    return ans;
}
main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}