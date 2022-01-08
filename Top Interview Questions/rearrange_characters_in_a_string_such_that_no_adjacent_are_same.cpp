#include <bits/stdc++.h>
using namespace std;

string rearrange_characters_in_string(string str)
{
    //first count the frequency of all characters in string using hashing
    unordered_map<char, int> mp;
    for (auto c : str)
    {
        mp[c]++;
    }

    /*in priority_queue (max heap) store the frequency, char pairs.
    Using max heap so that the most frequent character will be at top and we can add it our result by popping */
    priority_queue<pair<int, char>> pq;
    for (auto i : mp)
    {
        pq.push({i.second, i.first});
    }
    string ans = "";

    //while there are more than 1 characters left to be added
    while (pq.size() > 1)
    {

        /* pop two most frequent elements and add their char to answer string, 
        doing this to distribute the frequent characters enevly so that no two will be adjacent at the end */
        auto c1 = pq.top();
        pq.pop();
        auto c2 = pq.top();
        pq.pop();
        ans += c1.second;
        ans += c2.second;

        //after adding 1 character, if there are still more left then add them to heap again with reduced count by 1
        if (--c1.first > 0)
            pq.push(c1);
        if (--c2.first > 0)
            pq.push(c2);
    }

    /* if the last element left occurs only once then we can add it to our answer,
    if it occurs more than 1 then two of them will be adjacent so we return empty string denoting that it's not possible */
    if (pq.size())
    {
        if (pq.top().first == 1)
            ans += pq.top().second;
        else
            return "";
    }
    return ans;
} //time complexity O(N*log(N)) space complexity O(N)

//below is the optimal approach
/*
Approach:
    1.first of all we make a vector of pair that stores the occurences of a char and the char itself
    2. sort it to get the char with max occurence at the back
    3. take result string of input string size with all the characters ""
    4. initialize index=0 which will be increasing by two every time in the below loop 
        whenever the index reach the end of the result string we initialize it to 1 and increase it by two like before 
        to store the character in alternate indexes in the result string and we do the step-4, 1 time
    5.now loop through the vector from the end to the beginning and do the following for every index i
        1. if(count of curent character is not zero ) we do the following:
            a. we store the occurence of the curent char at temp and char at c
            b. while(temp--) do the following:
                if the index reached the end of the result string, and
                if count==0 we initialize index with one increase count,
                else break
                store the curent char in res at index
                if(index > 0 and res[index-1] == res[index]) i.e. we cant rearrange string s so return empty string
                increment index by 2
*/
string rearrange_string_optimized(string s)
{
    vector<pair<int, char>> counts(26);
    for (auto &c : s)
    {
        counts[c - 'a'].first++;
        counts[c - 'a'].second = c;
    }
    sort(counts.begin(), counts.end());
    int index = 0;
    int count = 0;
    string res(s.size(), ' ');
    for (int i = counts.size() - 1; i >= 0; i--)
    {
        if (counts[i].first)
        {
            int temp = counts[i].first;
            char c = counts[i].second;  
            //while curent character occurs in the string
            while (temp--)
            {
                if (index >= s.size())
                {
                    //if count is 1 then it means that we have traversed the res string two times so we should now break the loop
                    if (count == 1)
                        break;
                    //else we have just completed the 1st traversal ie. visited even indexes of the res string
                    count++;
                    // so we should now start index at 1 to visit the odd indexes of the res string
                    index = 1;
                }
                //storing the curent character in res at index
                res[index] = c;
                //we cant rearrange the string anyway
                if (index > 0 and res[index - 1] == res[index])
                    return "";
                //we always increment index by two ,for storing the characters alternately in the res
                index += 2;
            }
        }
    }
    return res;
} //time complexity O(N) space complexity O(1 ) as we at most take 26 memory locations as vector
int main()
{
    string str;
    cin >> str;
    auto res = rearrange_string_optimized(str);
    cout << res << endl;
    return 0;
}