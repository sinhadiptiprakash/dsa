#include<bits/stdc++.h>
using namespace std;
string minWindow(string str, string pat)
{
    int MAX_CHARS = 256;
    int len1 = str.length();
    int len2 = pat.length();

    // Check if string's length
    // is less than pattern's
    // length. If yes then no such
    // window can exist
    if (len1 < len2)
    {
        return "";
    }

    vector<int> hash_pat(MAX_CHARS, 0);
    vector<int> hash_str(MAX_CHARS, 0);

    // Store occurrence ofs characters
    // of pattern
    for (int i = 0; i < len2; i++)
        hash_pat[pat[i]]++;

    int start = 0, start_index = -1, min_len = INT_MAX;

    // Start traversing the string
    // Count of characters
    int count = 0;
    for (int j = 0; j < len1; j++)
    {

        // Count occurrence of characters
        // of string
        hash_str[str[j]]++;

        // If string's char matches with
        // pattern's char
        // then increment count
        if (hash_str[str[j]] <= hash_pat[str[j]])
            count++;

        // if all the characters are matched
        if (count == len2)
        {

            // Try to minimize the window
            while (hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0)
            {

                if (hash_str[str[start]] > hash_pat[str[start]])
                    hash_str[str[start]]--;
                start++;
            }

            // update window size
            int len_window = j - start + 1;
            if (min_len > len_window)
            {
                min_len = len_window;
                start_index = start;
            }
        }
    }

    // If no window found
    if (start_index == -1)
    {
        return "";
    }

    // Return substring starting from start_index
    // and length min_len
    return str.substr(start_index, min_len);
} //time complexity O(N) space complexity O(1)
int main(){
    return 0;
}