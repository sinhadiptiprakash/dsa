// detection fraud in transactions
#include<bits/stdc++.h>
using namespace std;
vector<string> get_fraud_id(vector<string> &uid, int threshold)
{
    vector<string> result;
    unordered_map<string, int> ump;
    vector<string> temp;
    int idx;
    string word;
    for (idx = 0; idx < uid.size(); idx++)
    {
        stringstream ss(uid[idx]);
        while (ss >> word)
        {
            temp.push_back(word);
        }
        if (temp[0] != temp[1])
        {
            ump[temp[0]]++;
            ump[temp[1]]++;
        }
        else
            ump[temp[0]]++;
        temp.clear();
    }
    for (auto &i1 : ump)
    {
        if (i1.second >= threshold)
            result.push_back(i1.first);
    }

    sort(result.begin(), result.end(), [](const string &a, const string &b)
         { return stoi(a) > stoi(b); });

    return result;
}

int main()
{

    vector<string> id = {"345366 89921 45", "029323 38239 23",
                         "38239 345366 15", "029323 38239 77",
                         "345366 38239 23", "029323 345366 13",
                         "38239 38239 23"};
    vector<string> res(get_fraud_id(id, 3));
    for (auto &s1 : res)
        cout << s1 << " ";

    return 0;
}