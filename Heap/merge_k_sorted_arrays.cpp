#include <bits/stdc++.h>
using namespace std;
// using heap
vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
{
    // storing the element and its array no. i.e. from which array we pick this element
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;
    // push first elements of each sorted array in the heap
    for (int i = 0; i < k; i++)
        heap.push({arr[i][0], {i, 0}});
    vector<int> result;
    // now get one element from the heap and put it in the result
    // now check from where we picked the curent element,from there we pick next element and put it in heap
    while (!heap.empty())
    {
        auto tp = heap.top();
        result.push_back(tp.first);
        heap.pop();
        if (tp.second.second + 1 < k)
            heap.push({arr[tp.second.first][tp.second.second + 1], {tp.second.first, tp.second.second + 1}});
    }
    return result;
} // time complexity O(k^2*log(k)) and space complexity O(k)

// same as above approach but without using pair
struct Data
{
    int element;
    int arrNo;
    int index;
    // constructor
    Data(int e, int a, int i) : element(e), arrNo(a), index(i) {}
};
struct comp
{
    bool operator()(Data a, Data b)
    {
        return a.element > b.element;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
{
    priority_queue<Data, vector<Data>, comp> minHeap;
    vector<int> res;
    for (int i = 0; i < k; i++)
        minHeap.push(Data(arr[i][0], i, 0));
    while (!minHeap.empty())
    {
        auto topNode = minHeap.top();
        minHeap.pop();
        res.push_back(topNode.element);
        if (topNode.index + 1 < k)
        {
            minHeap.push(Data(arr[topNode.arrNo][topNode.index + 1], topNode.arrNo, topNode.index + 1));
        }
    }
    return res;
}
int main()
{
    int k;
    cin >> k;
    vector<vector<int>> arr(k, vector<int>(k));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> arr[i][j];
        }
    }
    auto res = mergeKSortedArrays(arr, k);
    for (int i : res)
        cout << i << ' ';
    cout << endl;
    return 0;
}