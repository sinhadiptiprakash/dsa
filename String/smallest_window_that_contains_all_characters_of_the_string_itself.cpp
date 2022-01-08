#include <bits/stdc++.h>
using namespace std;
// This is the Brute Force method of solving the problem using HashMap.
/*
Algorithm : 
1. Store all distinct characters of the given string in a hash_map.
2. Take a variable count and initialize it with value 0.
3. Generate the substrings using two pointers.
4. Now check whether generated substring is valid or not-: 
    (i).As soon we find that the character of the substring generated has not been encountered before, 
        increment count by 1.
    (ii).We can use a visited array of max_chars size to find whether 
        the current character has been encountered before or not.
    (iii).If count is equal to equal to size of hash_map the substring generated is valid
    (iv). If it is a valid substring, compare it with the minimum length substring already generated.
*/
const int MAX_CHARS = 256;

string smallest_window(string str)
{
    int n = str.length();
    // Count all distinct characters.
    int dist_count = 0;
    unordered_map<int, int> hash_map;
    for (int i = 0; i < n; i++)
    {
        hash_map[str[i]]++;
    }

    dist_count = hash_map.size();
    int size = INT_MAX;
    string res;
    // Now follow the algorithm
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int visited[256] = {0};
        string sub_str = "";
        for (int j = i; j < n; j++)
        {
            if (visited[str[j]] == 0)
            {
                count++;
                visited[str[j]] = 1;
            }
            sub_str += str[j];
            if (count == dist_count)
                break;
        }
        if (sub_str.length() < size && count == dist_count)
        {
            res = sub_str;
            size = res.length();
        }
    }
    return res;
} //time complexity O(N^2) spce complexity O(N)

//Method 2: Here we have used Sliding Window technique to arrive at the solution.
//This technique shows how a nested for loop in few problems can be converted to single for loop
//and hence reducing the time complexity.
/*
Algorithm : 
1.Maintain an array (visited) of maximum possible characters (256 characters) 
    and as soon as we find any new character in the string, mark that index in the array (this is to count all distinct characters in the string).
2.Take two pointers start and end which will mark the start and end of window.
3.Take a counter=0 which will be used to count distinct characters in the window.
4.Now start reading the characters of the given string and 
    if we come across a character which has not been visited yet increment the counter by 1.
5.If the counter is equal to total number of distinct characters, Try to shrink the window.
6.For shrinking the window -: 
    i).If the frequency of character at start pointer is greater than 1 increment the pointer as it is redundant.
    ii). Now compare the length of present window with the minimum window length.
*/
string smallest_window_efficient(string str)
{
    int n = str.length();

    // Count all distinct characters.
    int dist_count = 0;
    bool visited[MAX_CHARS] = {false};
    for (int i = 0; i < n; i++)
    {
        if (!visited[str[i]])
        {
            visited[str[i]] = true;
            dist_count++;
        }
    }
    // Now follow the algorithm discussed in below
    // post. We basically maintain a window of characters
    // that contains all characters of given string.
    int start = 0, start_index = -1, min_len = INT_MAX;

    int count = 0;
    int curr_count[MAX_CHARS] = {0};
    for (int j = 0; j < n; j++)
    {
        // Count occurrence of characters of string
        curr_count[str[j]]++;

        // If any distinct character matched, then increment count
        if (curr_count[str[j]] == 1)
            count++;

        // if all the characters are matched
        if (count == dist_count)
        {
            // Try to minimize the window i.e., check if any character is occurring more no. of times
            // than its occurrence in pattern, if yes then remove it from starting and also remove
            // the useless characters.
            while (curr_count[str[start]] > 1)
            {
                if (curr_count[str[start]] > 1)
                    curr_count[str[start]]--;
                start++;
            }

            // Update window size
            int len_window = j - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }

    // Return substring starting from start_index
    // and length min_len
    return str.substr(start_index, min_len);
}
int main()
{
    string str;
    cin >> str;
    cout << smallest_window(str) << endl;
    return 0;
}