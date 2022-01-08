#include <bits/stdc++.h>
using namespace std;
//brute force approach
//for every string check if there are anagrams at the right side of this string by computing and comparing hash values
vector<vector<string>> group_anagrams(vector<string> strings)
{
    vector<vector<string>> groups;
    int n = strings.size();
    //for checking wheather a string is already put in a group of anagrams
    vector<bool> grouped(n, false);
    for (int i = 0; i < n; i++)
    {
        //if curent string is not grouped yet
        if (!grouped[i])
        {
            int main_map[26] = {0};
            for (char c : strings[i])
            {
                main_map[c - 'a']++;
            }
            //now push this very sting in a separate grup
            groups.push_back({strings[i]});
            //make this as grouped
            grouped[i] = true;
            //now computing the occurences of the other strings in the right side
            for (int j = i + 1; j < n; j++)
            {
                //compute occurences of the strings[j] if same occurences as teh strings[i] then group theis together
                int aux_map[26] = {0};
                for (char c : strings[j])
                {
                    aux_map[c - 'a']++;
                }
                //comparing occurences of the strings[i] and strings[j]
                bool flg = true;
                for (int k = 0; k < 26; k++)
                {
                    if (main_map[k] != aux_map[k])
                        flg = false;
                }
                //if both occurences are same then push back this j th string into the group of the ith string i.e. the last added group
                if (flg)
                {
                    groups.back().push_back(strings[j]);
                    //also make this gouped
                    grouped[j] = true;
                }
            }
        }
    }
    return groups;
} //time complexity O(N*N*26) space complexity O(N)

//better approach is to use sorting the every string and map them
vector<vector<string>> group_anagrams2(vector<string> strings)
{
    int n = strings.size();
    vector<vector<string>> groups;
    //below map stores the sorted string and its value as a group of its anagrams
    unordered_map<string, vector<string>> map;
    //sorted stores curent string in sorted order temporarily
    string sorted;
    for (int i = 0; i < n; i++)
    {
        sorted = strings[i];
        sort(sorted.begin(), sorted.end());
        //if this sorted already in the map we should include it into its corresponding goup
        if (map.find(sorted) != map.end())
        {
            map[sorted].push_back(strings[i]);
        }
        //otherwise we make a new group with this string
        else
        {
            map[sorted] = {strings[i]};
        }
    }
    //storing the groups stored in the map as value,in the resultant groups
    for (auto it : map)
    {
        groups.push_back(it.second);
    }
    return groups;
} //time complexity O(N*(K*log(k))) where k is the length of the longest string in the input strings

//below is not efficient approach but yes its another approach which dont use sorting rather it uses hasmap for each string as a key in a map of hash_map and vector<strings>
vector<vector<string>> group_anagrams3(vector<string> strings)
{
    int n = strings.size();
    vector<vector<string>> res;
    //we cant take an unordered map where vector of int as a key
    map<vector<int>, vector<string>> main_map;
    for (int i = 0; i < n; i++)
    {
        //compute the occurences in a vector of int hash
        vector<int> hash(26, 0);
        for (char c : strings[i])
        {
            hash[c - 'a']++;
        }
        if (main_map.find(hash) != main_map.end())
        {
            main_map[hash].push_back(strings[i]);
        }
        else
            main_map[hash].push_back({strings[i]});
    }
    for (auto it : main_map)
    {
        res.push_back(it.second);
    }
    return res;
}

int main()
{
    vector<string> strings = {"eat", "tan", "bat", "ate", "nat", "love", "tab"};
    auto res = group_anagrams3(strings);
    for (auto vctr : res)
    {
        for (auto str : vctr)
        {
            cout << str << ' ';
        }
        cout << endl;
    }
    return 0;
}