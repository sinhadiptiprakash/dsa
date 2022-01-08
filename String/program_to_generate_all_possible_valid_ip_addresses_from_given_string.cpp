#include <bits/stdc++.h>
using namespace std;
/*
A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255.
The numbers cannot be 0 prefixed unless they are 0.
Approach1: Split the string with ‘ . ‘ and then check for all corner cases. Before entering the loop,
check the size of the string. Generate all the possible combinations using looping through the string.
If IP is found to be valid then return the IP address, else simply return the empty list.
Below is the implementation of the above approach :
*/
// this function checks in part if a part of ip address is valid or not
bool is_valid(string s)
{
    int n = s.size();
    // as each part should be from 0 to 255 so the max. length of a part should be 3
    if (n > 3)
        return false;
    // if the part is not 0 and
    if (n == 3 || n == 2)
    {
        // starts with 0 it is not a valid one
        if (s[0] == '0')
            return false;
        int num = stoi(s);
        // if the part is not within the range from 0 to 255
        if (num > 255 || num < 0)
            return false;
    }
    return true;
}
vector<string> restore_ip_addresses(string s)
{
    vector<string> ans;
    int n = s.size();
    // excluding 3 dots ip can contain at most 12 character and should contain 4 characters
    if (n > 12 || n < 4)
        return ans;
    // we try every segment
    for (int i = 1; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                // first part from starting and length of (i-0)
                string p1 = s.substr(0, i - 0);
                // 2nd part from i and length of (j-i) and so on
                string p2 = s.substr(i, j - i);
                string p3 = s.substr(j, k - j);
                string p4 = s.substr(k, n - k);
                // if all the four parts are valid i.e. all the four parts constitute a full valid ip address,
                // store it in the ans with 3 dots
                if (is_valid(p1) && is_valid(p2) && is_valid(p3) && is_valid(p4))
                {
                    string tops = p1 + "." + p2 + "." + p3 + "." + p4;
                    ans.push_back(tops);
                }
            }
        }
    }
    return ans;
} // time complexity O(N^3) space complexity O(1)

// below is the recursive-backtracking implementation of the above approach

bool isValid(string s1)
{
    if (s1.size() > 3 || s1.size() == 0)
        return false;
    if (s1.size() > 1 && s1[0] == '0')
        return false;
    // using stoi to convert string to integer
    if (s1.size() && stoi(s1) > 255)
        return false;
    return true;
}
// here i is the index from where we are inspecting or recurring the rest string
// ans is for storing the ans
// dots maintains how many dots we have pushed into the generated ip
// s is the main string
// temp stores already formed valid part of the string
void recur(int i, int dots, string temp, vector<string> &ans, string s)
{
    // we have to place 3 dots in the string to make 4 partitions
    if (dots == 3)
    {
        // pushing last partition after checking its validity
        if (isValid(s.substr(i)))
            ans.push_back(temp + s.substr(i));
        return;
    }

    // placing the dot at every valid position
    for (int j = i; j < s.size(); j++)
    {
        if (isValid(s.substr(i, j - i + 1)))
        {
            temp.push_back(s[j]);
            temp.push_back('.');
            recur(j + 1, dots + 1, temp, ans, s);
            // removing the dot after calling recur function
            // note that we don't remove the last digit that was placed in temp string as we just have to change positions of dots only and not digits in string
            temp.pop_back();
        }
    }
    return;
}
vector<string> restoreIpAddresses(string s)
{
    vector<string> ans;
    if (s.size() < 4)
        return ans;
    recur(0, 0, "", ans, s);
    return ans;
}

int main()
{
    string str;
    cin >> str;
    auto res = restore_ip_addresses(str);
    for (auto it : res)
        cout << it << endl;
    return 0;
}