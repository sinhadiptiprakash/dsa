#include <bits/stdc++.h>
using namespace std;

// for approach and prolem refer https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
// watch Tech Dose's video for better understanding

//numbers of possible characters in the string let 256
#define d 256
vector<int> rabin_karp(string text, string pattern, int prime)
{
    vector<int> result;
    //p is a large prime number to avoid hashing collision
    int n = text.length();
    int m = pattern.size();
    int pattern_hash = 0;
    int text_hash = 0;
    int h = 1;
    int i, j;
    // The value of h would be "pow(d, m-1)%prime"
    for (i = 0; i < m - 1; i++)
        h = (h * d) % prime;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < m; i++)
    {
        pattern_hash = (d * pattern_hash + pattern[i]) % prime;
        text_hash = (d * text_hash + text[i]) % prime;
    }
    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++)
    {

        // Check the hash values of current window of text and pattern.
        //If the hash values match then only check for characters on by one
        if (pattern_hash == text_hash)
        {
            /* Check for characters one by one */
            for (j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == m)
                result.push_back(i);
        }

        // Calculate hash value for next window of text: Remove leading digit, add trailing digit
        if (i < n - m)
        {
            text_hash = (d * (text_hash - text[i] * h) + text[i + m]) % prime;

            // We might get negative value of t, converting it to positive
            if (text_hash < 0)
                text_hash = (text_hash + prime);
        }
    }
    return result;
}
int main()
{
    string text, pattern;
    cin >> text >> pattern;
    const int prime = 1001;
    auto res = rabin_karp(text, pattern, prime);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}