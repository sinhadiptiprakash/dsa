#include<bits/stdc++.h>
using namespace std;
int segmentTree[4 * 100005];
vector<int> lazy(4 * 100005, 0);
//below is the implementation of segment tree for range minimum query(rmq)
void buildSegmentTree(int a[], int start, int end, int index)
{
    //base case
    if (start == end)
    {
        segmentTree[index] = a[start];
        return;
    }
    int mid = start + (end - start) / 2;
    buildSegmentTree(a, start, mid, 2 * index + 1);
    buildSegmentTree(a, mid + 1, end, 2 * index + 2);
    //backtracking
    segmentTree[index] = min(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
}
int queryUtil(int index, int low, int high, int l, int r)
{
    //if the range is withing the curent range then we should return the value at the curent index
    if (low >= l && high <= r)
        return segmentTree[index];
    //if the range is outside then return INT_MAX in case of a range min query segment tree
    if (high < l || low > r)
        return INT_MAX;
    int mid = low + (high - low) / 2;
    int leftData = queryUtil(2 * index + 1, low, mid, l, r);
    int rightData = queryUtil(2 * index + 2, mid + 1, high, l, r);
    return min(leftData, rightData);
}
//in below function the index: the index of segmentTree node,low-high is the whole range
//,node: index of the node to be updated and val: is the value with which the value is updated
//if it is range sum query segment tree
void pointUpdateUtil(int index, int low, int high, int node, int val)
{
    //base case
    if (low == high)
    {
        segmentTree[index] = val;
        return;
    }
    int mid = low + (high - low) / 2;
    if (node <= mid && node >= low)
        pointUpdateUtil(2 * index + 1, low, mid, node, val);
    else
        pointUpdateUtil(2 * index + 2, mid + 1, high, node, val);
    //backtracking
    segmentTree[index] = min(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
}
//below function is used to update in range
//below functio is designed to show in sum range query. i.e. the segment tree stores the sum of ranges
void rangeUpdateUtil(int index, int low, int high, int l, int r, int val)
{
    //is there an update pending in the cuerent index ?
    if (lazy[index] != 0)
    {
        //update the segment tree value of curent index
        //because the curent index has (high-low+1) no. of childs
        segmentTree[index] += (high - low + 1) * val;
        if (low != high)
        {
            //propagating the updates
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        //as we have updated the curent index in segment tree there is no update pending in the curent index
        lazy[index] = 0;
    }
    //if range is outside the range return
    if (low > r || high < l || low > high)
        return;
    //if curent range is within the range
    if (low >= l && high <= r)
    {
        //update the curent index at segment tree
        segmentTree[index] += (high - low + 1) * val;
        if (low != high)
        {
            //propagating the lazy updates to the left and right childs
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        return;
    }
    int mid = low + (high - low) / 2;
    rangeUpdateUtil(2 * index + 1, low, mid, l, r, val);
    rangeUpdateUtil(2 * index + 2, mid + 1, high, l, r, val);
    //backtracking
    segmentTree[index] = segmentTree[2 * index + 1] + segmentTree[2 * index + 2];
}
//below function is for query over a range sum segment tree having lazy propagation
int querySumLazy(int index, int low, int high, int l, int r)
{
    //at first we check wheather the curent index having an update pending
    if (lazy[index] != 0)
    {
        //updating the curent index in segment tree
        //and leaving the childs' updates pending
        segmentTree[index] = (high - low + 1) * lazy[index];
        if (low != high)
        {
            //propagating the lazy updates to the left and right childs
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        //as the curent index in segment tree is updated, the curent index does'nt have any lazy updates pending
        //so we have to make it 0
        lazy[index] = 0;
    }
    //if the curent range is outside the l-r range return 0 in case of range sum queries
    if (low > l || high < r || low > high)
        return 0;
    //if the curent range is within the l-r range return the value at index in segment tree
    if (low >= l && high <= r)
    {
        return segmentTree[index];
    }
    int mid = low + (high - low) / 2;
    return querySumLazy(2 * index + 1, low, mid, l, r) + querySumLazy(2 * index + 2, mid + 1, high, l, r);
}
int query(int l, int r)
{
    return queryUtil(0, 0, 10, l, r);
}
void pointUpdate(int node, int val)
{
    pointUpdateUtil(0, 0, 10, node, val);
}
int main(){
    return 0;
}