#include <bits/stdc++.h>
using namespace std;
//for problem and approach refer https://www.geeksforgeeks.org/word-break-problem-dp-32/
//map for dictionary of words
unordered_map<string, bool> dictionary;
unordered_map<string, bool> dp;
//below is the recursive backtracking approach
bool word_break_recursive(string str, int n)
{
    //if the string is empty then its always returns true
    if (n == 0)
        return true;
    // Try all prefixes of lengths from 1 to size
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        temp += str[i];
        //if we get the prefix temp at the dictionary we check recursively call for the rest of the string
        //if both are true then the resutl is true
        if (dictionary.find(temp) != dictionary.end())
        {
            if (word_break_recursive(str.substr(i + 1), n - i - 1))
                return true;
        }
    }
    return false;
}
//below function uses the above recursive function
bool word_break_problem(string str, vector<string> words)
{
    //first of all we put all the words in an unordered_map to check in constant time wheather a particular string exists in the dictionary
    for (auto word : words)
    {
        dictionary[word] = true;
    }
    //now call the utility function for answer
    return word_break_recursive(str, str.length());
}
//time complexity O(2^N) space compexity O(N)

//below is the memoization version of the above recursive backtracking approach
bool word_break_memoization(string str, int n, unordered_map<string, bool> &dp)
{
    if (n == 0)
        return true;
    if (dp.find(str) != dp.end())
        return dp[str];
    string temp = "";
    for (int i = 0; i < n; i++)
    {
        temp += str[i];
        if (dictionary.find(temp) != dictionary.end())
        {
            if (word_break_memoization(str.substr(i + 1), n - i - 1, dp))
                return dp[str] = true;
        }
    }
    return dp[str] = false;
} //Time: O(w.n^2) Space: O(n*(n+1))/2) because we are storing all substrings's results in dp

//below is the better memory optimized memoization code
//Approach: We maintain the results of the previous subproblems in a vector dp,
//according to the starting index. While calling the recursive function,
//we first see the results array to check if the problem has been solved already or not.
//If it has been solved, we just return that result, instead of going through the whole recursion again.
bool word_break_memoization_efficient(string str, int start_index, vector<int> &dp)
{
    // if the string is empty
    if (start_index >= str.size())
        return true;
    // if we have already calculated this subproblem return it
    if (dp[start_index] != -1)
        return dp[start_index];

    //initialize this subproblem's result as 0
    dp[start_index] = 0;
    //create an empty prefix string
    string prefix = "";
    for (int i = start_index; i < str.size(); i++)
    {
        prefix += str[i];
        // if the prefix is available in the dictionary then we have to check for the rest subproblems
        // so if the prefix is available in the dictionary and checking the solutions for the subproblem(i+1 to end)
        if (dictionary.find(prefix) != dictionary.end() && (dp[start_index] = word_break_memoization_efficient(str, i + 1, dp)))
        {
            break;
        }
    }
    return dp[start_index];
}
//below is the bottom up approach
bool wordBreak(string s, vector<string> &dict)
{
    if (dict.size() == 0)
        return false;
    int n = s.size();
    bool t[n + 1];
    memset(t, false, sizeof(t));
    t[0] = true;
    // we split the string at every possible values of i
    for (int i = 1; i <= s.size(); i++)
    {
        // we check every solution of sub-problmes from j=0 to i-1 in bakcwards
        for (int j = i - 1; j >= 0; j--)
        {
            if (t[j])
            {
                string str = s.substr(j, i - j);
                auto it = dictionary.find(str); // search for str in dictionary
                // we the string is in the dictionary
                if (it != dictionary.end())
                {
                    t[i] = true;
                    break;
                }
            }
        }
    }

    return t[n];
}
int main()
{
    string str = "Iamcoder";
    vector<string> words = {"I", "am", "a", "leet", "coder"};
    for (auto word : words)
        dictionary[word] = true;
    vector<int> dp(str.size() + 1, -1);
    cout << wordBreak(str, words) << endl;
    return 0;
}