#include <bits/stdc++.h>
using namespace std;
// for the question and the approach refer gfg & https://helloml.org/word-wrapping-problem-dynamic-programming/
// for better understanding the approach watch tushar video https://www.youtube.com/watch?v=RORuwHiblPc
// here's the approach:
/*Solution:
 * Badness - We define badness has square of empty spaces in every line.
 * So 2 empty space on one line gets penalized as 4 (2^2) while 1 each empty space on 2 lines gets
 * penalized as 2(1 + 1). So we prefer 1 empty space on different lines over 2 empty space on
 * one line.
 * 
 * For every range i,j(words from i to j) find the cost of putting them on one line. If words 
 * from i to j cannot fit in one line cost will be infinite. Cost is calculated as square of
 * empty space left in line after fitting words from i to j.
 * 
 * Then apply this formula to get places where words need to be going on new line.
 * minCost[i] = minCost[j] + cost[i][j-1]
 * Above formula will try every value of j from i to len and see which one gives minimum 
 * cost to split words from i to len.
 * 
 * Space complexity is O(n^2)
 * Time complexity is O(n^2)
 * */
void word_wrap(int arr[], int n, int k)
{
    int cost[n][n];
    //cost[i][j] denotes no. of spaces at the end of a line after putting the words from i to j in one line
    for (int i = 0; i < n; i++)
    {
        //after placing the ith word in the ith line at the beginning
        cost[i][i] = k - arr[i];
        for (int j = i + 1; j < n; j++)
        {
            //if we place more than one word in a line then there will be a space between two consequtive words
            //so we have to subtract 1 for that
            cost[i][j] = cost[i][j - 1] - arr[j] - 1;
        }
    }
    //now we modify cost to save memory space
    //now cost[i][j] denotes cost of putting words from i to j in the line i
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // if cost is -ve i.e. we cant no words from jth word to the end so we update cost to infinite.
            if (cost[i][j] < 0)
                cost[i][j] = INT_MAX;
            // if it is the last word and its cost is >=0 then it means it is the last line so we should update it to 0
            else if (j == n - 1 && cost[i][j] >= 0)
                cost[i][j] = 0;
            // otherwise we just need to squre the no. of spaces to update the cost
            else
                cost[i][j] = cost[i][j] * cost[i][j]; // if cost is +ve or 0 then square that, that will be the loss at that point.
        }
    }
    //min[i] denotes the min. cost to put the words from ith word to the end
    int min[n];
    //ans[i] denotes the index of the word that can be place from ith word with cost min[i]
    int ans[n];
    //we start i and j from right side and go backwards we can do the opposite as well
    //v.v.i. point:
    //for a particular value of i,j
    //we first check wheather words from i to j lie in a single line if so we put the value in min[i]
    //if not then i.e. cost[i][j]==INT_MAX, we determine at which point we should segregate the line
    //i.e. we check for all possible values for j where we can segregate the line so the cost is mininmum
    //in that case the cost will be min[j]+cost[i][j-1],
    // i.e. (min cost so far for wrapping words from j to end)+(cost of including words from i to j)
    for (int i = n - 1; i >= 0; i--)
    {
        //we initialize min[i] with the value of last column of ith line and go backwards
        min[i] = cost[i][n - 1];
        //we assume that from i we can add all teh words upto end
        ans[i] = n;
        // we are trying to segregate the line at j for all possible values of j greater than i
        for (int j = n - 1; j > i; j--)
        {
            //we check wheather words from i to j-1 lie in a single line
            if (cost[i][j - 1] == INT_MAX)
                continue;
            // if cost of including words from i to j-1 and min cost sofar for wrapping words from j to end
            // is less than min[i] sofar we update min[i]
            if (min[i] > cost[i][j - 1] + min[j])
            {
                min[i] = cost[i][j - 1] + min[j];
                // ans[i] denotes from i which word is to be considered
                ans[i] = j;
            }
        }
    }
    //printing the result using dfs like logic
    for (int i = 0; i < n; i = ans[i])
    {
        cout << i + 1 << "-" << ans[i] << endl;
    }
} //time complexity O(N^2) space complexity O(N^2)

int main()
{
    int words[] = {4, 2, 2, 5};
    int n = sizeof(words) / sizeof(words[0]);
    int M = 6;
    word_wrap(words, n, M);
    return 0;
}