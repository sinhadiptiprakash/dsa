#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
{
    sort(products.begin(), products.end());
    int a = 0;
    int b = products.size() - 1;

    vector<vector<string>> result(searchWord.size());
    for (int i = 0; i < searchWord.size() && a <= b; ++i)
    {
        while (
            a <= b &&
            // Skip products[a] if index i is not a match
            (products[a].size() <= i || products[a][i] != searchWord[i]))
        {
            ++a;
        }
        while (
            a <= b &&
            // Skip products[b] if index i is not a match
            (products[b].size() <= i || products[b][i] != searchWord[i]))
        {
            --b;
        }

        // Pick the first 3 starting from a,
        // but not going over b
        for (int k = a; k <= b && k < a + 3; ++k)
        {
            result[i].push_back(products[k]);
        }
    }
    return result;
}
int main()
{
    return 0;
}