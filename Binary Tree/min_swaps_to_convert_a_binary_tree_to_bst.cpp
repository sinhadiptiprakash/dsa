#include <bits/stdc++.h>
using namespace std;
struct BinaryTree
{
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
//Approach:
/*
The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing order of their value. 
So, find the inorder traversal of the Binary Tree and store it in the array and try to sort the array. 
The minimum number of swap required to get the array sorted will be the answer. 
Please refer to find minimum number of swaps required to get the array sorted in Searching & Sorting Folder.
*/
// function to get the inOrder traversal of a tree, the levelOrder traversal is given by the array arr
// we have to construct the inOrder traversal from this array and store it in res
// here also like inOrder traversal we first call for the left subtree then root then right subtree
void inOrder(vector<int> arr, int n, int index, vector<int> &res)
{
    if (index >= n)
        return;
    // if index is the index of parent node then its first child's index would be 2*index+1
    inOrder(arr, n, 2 * index + 1, res);
    res.push_back(arr[index]);
    // if index is the index of parent node then its second child's index would be 2*index+2
    inOrder(arr, n, 2 * index + 2, res);
}
//function returns min. swaps to sort the array for understanding it refer folder Searching Sorting
int minSwapsToSort(vector<int> &arr)
{
    int n = arr.size();
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        v[i] = {arr[i], i};
    sort(v.begin(), v.end());
    int swaps = 0;
    for (int i = 0; i < n;)
    {
        if (v[i].second == i)
            i++;
        else
        {
            swap(v[i], v[v[i].second]);
            swaps++;
        }
    }
    return swaps;
}
int minSwaps(vector<int> arr)
{
    int n = arr.size();
    vector<int> res;
    //first get the inOrder from the given level order in arr
    inOrder(arr, n, 0, res);
    return minSwapsToSort(res);
}
int main()
{
    vector<int> arr = {5, 6, 7, 8, 9, 10, 11};
    cout << minSwaps(arr) << endl;
    return 0;
}