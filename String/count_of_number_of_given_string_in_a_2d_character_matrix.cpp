#include <bits/stdc++.h>
using namespace std;
/*
Algorithm : 
1- Traverse matrix character by character and take one character as string start 
2- For each character find the string in all the four directions recursively 
3- If a string found, we increase the count 
4- When we are done with one character as start, we repeat the same process for the next character 
5- Calculate the sum of count for each character 
6- Final count will be the answer
*/

int utilitySearch(string word, int r, int c, string arr[], int maxR, int maxC, int index)
{
    int count = 0;
    //if r and c not out of the range
    if (r >= 0 && r <= maxR && c >= 0)
    {
        //if the curent character matches to starting character of the pattern then we continue inspecting next characters of the pattern
        if (c <= maxC && word[index] == arr[r][c])
        {
            // as we will be modifying arr content, we store the curennt arr[r][c] temporaryly which will be required when we will backtrack
            char res = word[index];
            // going to the next index of word to continue the pattern search
            index = index + 1;
            //we are modifying the arr
            arr[r][c] = 0;
            //if word[index]==0 that means it is end of the word string because from string length onwards string contains 0
            //if we have already matched all the characters of the word then we should increase the count
            if (word[index] == 0)
            {
                count = 1;
            }
            else //else we should coninue searcing for next index of word in all the four directions
            {
                //going right
                count = count + utilitySearch(word, r, c + 1, arr, maxR, maxC, index);
                //going left
                count = count + utilitySearch(word, r, c - 1, arr, maxR, maxC, index);
                //going up
                count = count + utilitySearch(word, r + 1, c, arr, maxR, maxC, index);
                //going down
                count = count + utilitySearch(word, r - 1, c, arr, maxR, maxC, index);
            }
            //bakctracking
            arr[r][c] = res;
        }
    }
    return count;
}

int findString(string word, int r, int c, string str[], int countR, int countC)
{
    int count = 0;
    //now for each and every chracter we check wheather that character is the starting of the pattern and if so we increase the count
    for (int i = 0; i < countR; ++i)
    {
        for (int j = 0; j < countC; ++j)
        {
            count = count + utilitySearch(word, i, j, str, countR - 1, countC - 1, 0);
        }
    }
    return count;
}

int main()
{
    string word = "FLOOD";
    string inp[] = {"FPLIOKOD", "FLOODYUT", "YFLOODPU", "FMLOSODT", "FILPOYOD", "FLOOOODE"};
    string str[(sizeof(inp) / sizeof(*inp))];
    for (int i = 0; i < (sizeof(inp) / sizeof(*inp)); ++i)
    {
        str[i] = inp[i];
    }
    cout << "Count of number of given string in 2D character array: " << findString(word, 0, 0, str, (sizeof(inp) / sizeof(*inp)), str[0].size()) << endl;
    return 0;
}