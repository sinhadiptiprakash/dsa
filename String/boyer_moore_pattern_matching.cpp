//for better understading the concept first refer https://www.youtube.com/watch?v=SzTyAV7OyhU
//after that refer https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
//after watching the video read the article at gfg it has a thorough explanation but read this after watching
//video otherwise it will be dificult to understand

//we will discuss the bad character heuristic method
/*
Bad Character Heuristic

The idea of bad character heuristic is simple. The character of the text which doesn’t match 
with the current character of the pattern is called the Bad Character. 
Upon mismatch, we shift the pattern until – 
1) The mismatch becomes a match
2) Pattern P moves past the mismatched character.

Case 1 – Mismatch become match:
    We will lookup the position of the last occurrence of the mismatched character in the pattern, 
    and if the mismatched character exists in the pattern, 
    then we’ll shift the pattern such that it becomes aligned to the mismatched character in the text T. 
Case 2 – Pattern move past the mismatch character 
    We’ll lookup the position of last occurrence of mismatching character in pattern 
    and if character does not exist we will shift pattern past the mismatching character
*/
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

// The preprocessing function for Boyer Moore's bad character heuristic
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    // Initialize all occurrences as -1
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Fill the actual value of last occurrence of a character
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

/* A pattern searching function that uses Bad Character Heuristic of Boyer Moore Algorithm */
void search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];

    /* Fill the bad character array by calling
    the preprocessing function badCharHeuristic()
    for given pattern */
    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is shift of the pattern with respect to text
    while (s <= (n - m))
    {
        int j = m - 1;

        /* Keep reducing index j of pattern while
        characters of pattern and text are
        matching at this shift s */
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        /* If the pattern is present at current
        shift, then index j will become -1 after
        the above loop */
        if (j < 0)
        {
            cout << "pattern occurs at shift = " << s << endl;

            /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }

        else
            /* Shift the pattern so that the bad character
            in text aligns with the last occurrence of
            it in pattern. The max function is used to
            make sure that we get a positive shift.
            We may get a negative shift if the last
            occurrence of bad character in pattern
            is on the right side of the current
            character. */
            s += max(1, j - badchar[txt[s + j]]);
    }
}

/* Driver code */
int main()
{
    string txt = "ABAAABCD";
    string pat = "ABC";
    search(txt, pat);
    return 0;
}
