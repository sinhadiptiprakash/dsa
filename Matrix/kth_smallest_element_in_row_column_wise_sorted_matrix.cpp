#include<bits/stdc++.h>
using namespace std;
//brute force approach:
//.add all the matrix elements in a min-heap and return/delete the kth elemeent
int kth_smallest_in_sorted_matrix(vector<vector<int>> &matrix,int k){
    int row=matrix.size();
    int col=matrix[0].size();
    //take a set as min_heap 
    set<int> min_heap;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            min_heap.emplace(matrix[i][j]);
        }
    }
    //remove k-1 elements from the min_heap
    for(int i=1;i<=k-1;i++){
        auto it=min_heap.begin();
        min_heap.erase(it);
    }
    //now kth smallest element will be at the beginning of the min_heap return it
    return (*min_heap.begin());
}//time complexity O((N^M)*log(N*M)) space complexity O(N*M)
//above approach does'nt utilize the fact that the matrix is sorted row-column wise

// Algorithm:
    // 1.The idea is to use min heap. Create a Min-Heap to store the elements
    // 2.Traverse the first row from start to end and build a min heap of elements from first row. 
        //A heap entry also stores row number and column number.
    // 3.Now Run a loop k times to extract min element from heap in each iteration
    // 4.Get minimum element (or root) from Min-Heap.
    // 5.Find row number and column number of the minimum element.
    // 6.Replace root with the next element from same column and min-heapify the root.
    // 7.Print the last extracted element, which is the kth minimum element
// Implementation:
int kth_smallest_in_sorted_matrix2(vector<vector<int>>& matrix,int k){
    int row=matrix.size();
    int col=matrix[0].size();
    //if k is not valid
    if(k<0 && k>=row*col)
        return INT_MAX;
    //taking set as min_heap where it stores element,row,col of the element
    set<pair<int,pair<int,int>>> min_heap;
    //store the elements and their locations of the first array into teh min_heap
    for(int i=0;i<col;i++){
        min_heap.insert({matrix[0][i],{0,i}});
    }
    pair<int,pair<int,int>> heap_root;
    for(int i=0;i<k;i++){
        heap_root=(*min_heap.begin());
        // getting the row and column locations of the heap_root element
        int r=heap_root.second.first;
        int c=heap_root.second.second;
        int next_val=(r<row-1?matrix[r+1][c]:INT_MAX);
        // remove root from the min_heap and add next_val
        cout<<heap_root.first<<' '<<r<<' '<<endl;
        min_heap.erase(heap_root);
        //insert next val into the min_heap
        min_heap.insert({next_val,{r+1,c}});
    }
    return heap_root.first;
}//time complexity O(K*log(n)) space complexity O(R) where R is the no. of elements in each row

//below is the binary-search approach this is same as finding median in a row-wise sorted matrix
//refer to median of sorted matrix question solution for understanding this appraoch
int kth_smallest_in_sorted_matrix_binary_search(vector<vector<int>> matrix,int k){
    int r=matrix.size();
    int c=matrix[0].size();
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<r; i++){
        // Finding the minimum element
        if (matrix[i][0] < min)
            min = matrix[i][0];
  
        // Finding the maximum element
        if (matrix[i][c-1] > max)
            max = matrix[i][c-1];
    }
    int desired = k;
    while (min < max){
        int mid = min + (max - min) / 2;
        int place = 0;
  
        // Find count of elements smaller than mid
        for (int i = 0; i < r; ++i)
            place += upper_bound(matrix[i].begin(), matrix[i].begin()+c, mid) - matrix[i].begin();
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}///time complexity O(32 * r * log(c)). The upper bound function will take log(c) time and is performed for each row. 
//And since the numbers will be max of 32 bit, 
//so binary search of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations. 
//Auxiliary Space : O(1)
int main(){ 
    int row,col;
    cin>>row>>col;
    vector<vector<int>> matrix(row,vector<int>(col));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)cin>>matrix[i][j];
    }
    int k;
    cin>>k;
    cout<<kth_smallest_in_sorted_matrix_binary_search(matrix,k)<<endl;
    return 0;
}