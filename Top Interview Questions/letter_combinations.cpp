#include <bits/stdc++.h>
using namespace std;
string getKeyString(char num)
{
    if (num == ('*' || '#' || '0' || '1'))
        return "";
    switch (num)
    {
    case '2':
        return "abc";
    case '3':
        return "def";
    case '4':
        return "ghi";
    case '5':
        return "jkl";
    case '6':
        return "mno";
    case '7':
        return "pqrs";
    case '8':
        return "tuv";
    case '9':
        return "wxyz";
    default:
        return "";
    }
}
vector<string> letterCombinations(string nums)
{
    if (nums.size() == 0)
        return {};
    if (nums.size() == 1)
    {
        string last = getKeyString(nums[nums.size() - 1]);
        vector<string> res(last.size(), "");
        for (int j = 0; j < last.size(); j++)
            res[j].push_back(last[j]);
        return res;
    }
    string lastDigit = getKeyString(nums[nums.size() - 1]);
    string rest = nums.substr(0, nums.size() - 1);
    vector<string> res = letterCombinations(rest);
    vector<string> result;
    int len = res.size();
    for (char character : lastDigit)
    {
        for (int i = 0; i < len; i++)
        {
            result.push_back(res[i] + character);
        }
    }
    return result;
}
int main()
{
    return 0;
}