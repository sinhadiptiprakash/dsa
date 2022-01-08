#include <bits/stdc++.h>
using namespace std;
//brute force approch
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}
// Function to print a substring str[low..high]
void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}
//this below function returns the length  of the maximum palindrome as well as prints that palindrome
int longest_palindrome_in_a_string_bf(string str)
{
    int n = str.length();
    int max_len = 1;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            //if the substring i...j is a palindrome we update max_len
            if (isPalindrome(str, i, j) && (j - i + 1) > max_len)
            {
                max_len = (j - i + 1);
                //update start of the palindrome as well
                start = i;
            }
        }
    }
    //printing the longest palindrome string
    printSubStr(str, start, start + max_len - 1);
    cout << endl;
    return max_len;
    //we can print the longest palindrome substring by storing the starting end ending eddress of hte max_len palindrome
} //time complexity O(N^3) as we are running two nested loops
//and inside that we run a isPal funtion which runs in O(N)
//space complexity O(1)

//below is a dynamic programming appraoch
// 1.Maintain a boolean table[n][n] that is filled in bottom up manner.
// 2.The value of table[i][j] is true, if the substring is palindrome, otherwise false.
// 3.To calculate table[i][j], check the value of table[i+1][j-1], if the value is true and str[i] is same as str[j], then we make table[i][j] true.
// 4.Otherwise, the value of table[i][j] is made false.
// 5.We have to fill table previously for substring of length = 1 and length =2 because
//  as we are finding , if table[i+1][j-1] is true or false , so in case of
//  (i) length == 1 , lets say i=2 , j=2 and i+1,j-1 doesn’t lies between [i , j]
//  (ii) length == 2 ,lets say i=2 , j=3 and i+1,j-1 again doesn’t lies between [i , j].

//this below function returns the length  of the maximum palindrome as well as prints that palindrome
int longest_palindrome_in_a_string_dp(string str)
{
    int n = str.length();
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));

    // All substrings of length 1 are palindromes
    int max_length = 1;

    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (str[i] == str[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            max_length = 2;
        }
    }
    // Check for lengths greater than 2. k is length of substring
    for (int k = 3; k <= n; k++)
    {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; i++)
        {
            // Get the ending index of substring from starting index i and length k
            int j = i + k - 1;
            // checking for sub-string from ith index to jth index iff str[i+1] to str[j-1] is a palindrome
            if (dp[i + 1][j - 1] && str[i] == str[j])
            {
                dp[i][j] = true;
                //updating max_length as well as start
                if (k > max_length)
                {
                    max_length = k;
                    start = i;
                }
            }
        }
    }
    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + max_length - 1);
    cout << endl;

    // return length of LPS
    return max_length;
} //time complexity O(N*N) space complexity O(N*N)

/*
1.The idea is to generate all even length and odd length palindromes and keep track of the longest palindrome seen so far.
2.To generate odd length palindrome, Fix a centre and expand in both directions for longer palindromes, i.e. fix i (index) as center and two indices as i1 = i+1 and i2 = i-1
3.Compare i1 and i2 if equal then decrease i2 and increase i1 and find the maximum length. 
4.Use a similar technique to find the even length palindrome.
5.Take two indices i1 = i and i2 = i-1 and compare characters at i1 and i2 and find the maximum length till all pair of compared characters are equal and store the maximum length.
6.Print the maximum length.
*/
// This function prints the longest palindrome substring (LPS) of str[]. It also returns the length of the longest palindrome
int longest_palindrome_in_a_string_efficient(string str)
{
    int n = str.length();
    int max_len = 1;
    int start = 0;
    int low, high;
    // One by one consider every character as center point of even and length palindromes
    for (int i = 1; i < n; ++i)
    {
        // Find the longest even length palindrome with center points as i-1 and i.
        low = i - 1;
        high = i;
        while (low >= 0 && high < n && str[low] == str[high])
        {
            if (high - low + 1 > max_len)
            {
                start = low;
                max_len = high - low + 1;
            }
            --low;
            ++high;
        }

        // Find the longest odd length palindrome with center point as i
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < n && str[low] == str[high])
        {
            if (high - low + 1 > max_len)
            {
                start = low;
                max_len = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + max_len - 1);
    cout << endl;
    return max_len;
} //time complexity O(N*N) and space complexity O(1)
int main()
{
    string str = "forgeeksskeegfor";
    cout << longest_palindrome_in_a_string_efficient(str) << endl;
    return 0;
}