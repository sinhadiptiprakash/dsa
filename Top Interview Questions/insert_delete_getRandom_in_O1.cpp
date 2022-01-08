#include <bits/stdc++.h>
using namespace std;
// using unordered set where insert is O(1), delete is O(1), getRandom is O(N)
class RandomizedSet
{
public:
    unordered_set<int> s;
    int size;
    RandomizedSet()
    {
        size = 0;
        srand(time(0));
    }

    bool insert(int val)
    {
        if (s.find(val) != s.end())
            return false;
        s.insert(val);
        size++;
        return true;
    }

    bool remove(int val)
    {
        if (s.find(val) == s.end())
            return false;
        s.erase(val);
        size--;
        return true;
    }

    int getRandom()
    {
        int index = rand() % size;
        int i = 0;
        for (auto num : s)
        {
            if (i == index)
                return num;
            i++;
        }
        return (*s.begin());
    }
};
// better approach using vector and unordered_map<int,int> where insert,delete,getRandom() all will be in O(1)
class RandomizedSet
{
    vector<int> v;
    unordered_map<int, int> mymap;

public:
    /** Initialize your data structure here. */
    RandomizedSet()
    {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val)
    {
        if (mymap.find(val) != mymap.end())
            return false;

        v.push_back(val);
        mymap[val] = v.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val)
    {
        if (mymap.find(val) == mymap.end())
            return false;

        auto it = mymap.find(val);
        v[it->second] = v.back();
        v.pop_back();
        mymap[v[it->second]] = it->second;
        mymap.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom()
    {
        return v[rand() % v.size()];
    }
};

static int fastio = []()
{
#define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
int main()
{
    return 0;
}