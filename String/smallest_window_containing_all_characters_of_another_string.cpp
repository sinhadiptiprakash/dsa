#include<bits/stdc++.h>
using namespace std;
//this problem  similar to the probelm of finding the smallest window that contains all characters fo the string itself

const int MAX_CHARS = 256;

string smallest_window(string str,string pat){
    int n = str.length();
    int m=pat.length();
    // Count all distinct characters of the pattern
    int dist_count = 0;
    unordered_map<char, int> pat_map;
    for (int i = 0; i < m; i++) {
        pat_map[pat[i]]++;
    }
 
    dist_count = pat.size();
    int size = INT_MAX;
    string res;
    // Now follow the algorithm 
    for (int i = 0; i < n; i++) {
        int count = 0;
        unordered_map<char,int> str_map;
        string sub_str = "";
        for (int j = i; j < n; j++) {
            if (pat_map.find(str[j])!=pat_map.end() && (str_map.find(str[j])==str_map.end() || str_map[str[j]]<pat_map[str[j]])) {
                count++;
                str_map[str[j]]++;
            }
            sub_str += str[j];
            if (count == dist_count)
                break;
        }
        if (sub_str.length() < size && count == dist_count)
        {
            res = sub_str;
            size=res.length();
        }
    }
    return res;
}//time complexity O(N^2) spce complexity O(N) the approach runs but time limit exceeded

//Method 2:
/* First check if the length of the string is less than the length of the given pattern, if yes then “no such window can exist “.
Store the occurrence of characters of the given pattern in a hash_pat[].
we will be using two pointer technique basically
Start matching the characters of pattern with the characters of string i.e. increment count if a character matches.
Check if (count == length of pattern ) this means a window is found.
If such a window found, try to minimize it by removing extra characters from the beginning of the current window.
delete one character from first and again find this deleted key at right, once found apply step 5 .
Update min_length.
Print the minimum length window.*/
string smallest_window_efficient(string str,string pat)
{
    int len1 = str.length();
    int len2 = pat.length();
 
    // Check if string's length
    // is less than pattern's
    // length. If yes then no such
    // window can exist
    if (len1 < len2) {
        return "";
    }
 
    int hash_pat[MAX_CHARS] = { 0 };
    int hash_str[MAX_CHARS] = { 0 };
 
    // Store occurrence ofs characters of pattern
    for (int i = 0; i < len2; i++)
        hash_pat[pat[i]]++;
 
    int start = 0, start_index = -1, min_len = INT_MAX;
 
    // Start traversing the string Count of characters
    int count = 0;
    for (int j = 0; j < len1; j++) {
       
        // Count occurrence of characters of string
        hash_str[str[j]]++;
 
        // If string's char matches with pattern's char then increment count
        if (hash_str[str[j]] <= hash_pat[str[j]])
            count++;
        // if all the characters are matched
        if (count == len2) {
            // Try to minimize the window
            while (hash_str[str[start]] > hash_pat[str[start]]  || hash_pat[str[start]] == 0) {
                if (hash_str[str[start]] > hash_pat[str[start]])
                    hash_str[str[start]]--;
                start++;
            }
            // update window size
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }
 
    // If no window found
    if (start_index == -1) {
        return "";
    }
 
    // Return substring starting from start_index
    // and length min_len
    return str.substr(start_index, min_len);
}
int main(){
    string str,pat;
    cin>>str>>pat;
    cout<<smallest_window_efficient(str,pat)<<endl;
    return 0;
}