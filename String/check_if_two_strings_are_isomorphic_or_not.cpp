#include <bits/stdc++.h>
using namespace std;
//two understand the problem carefully notice the testcase:aabc xyxz are not isomorphic because of the order
bool is_isomorphic(string str1, string str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }

    int hash1[26] = {0};
    int hash2[26] = {0};

    for (int i = 0; i < str1.size(); i++)
    {
        hash1[str1[i] - 'a']++;
        hash2[str2[i] - 'a']++;

        if (hash1[str1[i] - 'a'] != hash2[str2[i] - 'a'])
        {
            return false;
        }
    }

    return true;
} //time complexity O(N) sapce complexity O(no. of distinct characters)
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << is_isomorphic(str1, str2) << endl;
    return 0;
}