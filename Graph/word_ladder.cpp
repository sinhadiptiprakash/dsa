#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //using BFS
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();
        //maintain the word and its level
        queue<pair<string, int>> pendingVertices;

        unordered_set<string> visited;
        //push all the words in this set because initially all are unvisited
        for (auto it : wordList)
            visited.insert(it);

        //push the begin word in the queue
        pendingVertices.push({beginWord, 1});
        if (visited.count(beginWord) > 0)
            visited.erase(beginWord); //marking the begin word visited(if present)

        //start the bfs to get shortest path
        while (!pendingVertices.empty())
        {
            string curr = pendingVertices.front().first;
            int count = pendingVertices.front().second;
            pendingVertices.pop();

            //if we found the end word
            if (curr == endWord)
                return count;

            //travel to the neighbours of this string
            for (int i = 0; i < curr.size(); i++)
            {
                string temp = curr;
                for (int j = 0; j < 26; j++)
                {
                    temp[i] = ('a' + j);
                    if (visited.count(temp) > 0)
                    {
                        pendingVertices.push({temp, count + 1});
                        visited.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};

int main()
{
    return 0;
}