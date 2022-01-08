#include <bits/stdc++.h>
using namespace std;
// We can use Young Tableau to solve the above problem RECURSIVELY.
// The idea is to consider given 2D array as Young Tableau and call extract minimum O(N)
void young_tableau(vector<vector<int>> &matrix, int row, int col, int i, int j)
{
    // Find the values at down and right sides of mat[i][j]
    int down_value = (i + 1 < row ? matrix[i + 1][j] : INT_MAX);
    int right_value = (j + 1 < col ? matrix[i][j + 1] : INT_MAX);
    //base condition
    // If mat[i][j] is the down right corner element, return
    if (down_value == INT_MAX && right_value == INT_MAX)
        return;
    //now we will be replacing the curent element using the minimum element between down and right value
    // Move the smaller of two values (downVal and rightVal) to
    // mat[i][j] and recur for smaller value
    if (down_value < right_value)
    {
        matrix[i][j] = down_value;
        matrix[i + 1][j] = INT_MAX;
        young_tableau(matrix, row, col, i + 1, j);
    }
    else
    {
        matrix[i][j] = right_value;
        matrix[i][j + 1] = INT_MAX;
        young_tableau(matrix, row, col, i, j + 1);
    }
}
// A utility function to extract minimum element from Young tableau
int extractMin(vector<vector<int>> &matrix, int row, int col)
{
    int ret = matrix[0][0];
    // as after getting the minimum element we replace it with int_max
    matrix[0][0] = INT_MAX;
    young_tableau(matrix, row, col, 0, 0);
    return ret;
}
void print_elements_in_sorted_order_using_young_tableau(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    // for row*col number of times we find out the minimum from the matrix and print it
    for (int i = 0; i < row * col; i++)
    {
        cout << extractMin(matrix, row, col) << ' ';
    }
}
// Time complexity of extract minimum is O(N) and it is called O(N2) times.
// Therefore the overall time complexity is O(N3).

// below apporach uses min_heap
void print_elements_in_sorted_order_minHeap(vector<vector<int>> matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    set<int> min_heap;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            min_heap.emplace(matrix[i][j]);
        }
    }
    while (!min_heap.empty())
    {
        cout << *min_heap.begin() << ' ';
        min_heap.erase(min_heap.begin());
    }
} //time complexity is O(N^2*log(N^2)) space complexity O(N^2)

/*
A better solution is to use the approach used for merging k sorted arrays. 
The idea is to use a Min Heap of size N which stores elements of first column. 
The do extract minimum. In extract minimum, replace the minimum element with the next element of the row 
from which the element is extracted. Time complexity of this solution is O(N2LogN). 
*/
//below is that efficient approach
void print_elements_in_sorted_order_minHeap2(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    //store the elements and their locations of the first array into teh min_heap
    set<pair<int, pair<int, int>>> min_heap;

    for (int i = 0; i < col; i++)
    {
        min_heap.insert({matrix[0][i], {0, i}});
    }
    pair<int, pair<int, int>> heap_root;
    //for no. of elements of the matrix
    for (int i = 0; i < row * col; i++)
    {
        heap_root = (*min_heap.begin());
        // getting the row and column locations of the heap_root element
        int r = heap_root.second.first;
        int c = heap_root.second.second;
        //printing the root
        cout << heap_root.first << ' ';

        int next_val = (r < row - 1 ? matrix[r + 1][c] : INT_MAX);
        // remove root from the min_heap and add next_val
        min_heap.erase(heap_root);
        //insert next val into the min_heap
        min_heap.insert({next_val, {r + 1, c}});
    }
} //time complexity O(N*N*log(N)) space complexity O(N)
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << endl;
    print_elements_in_sorted_order_minHeap2(matrix);
    return 0;
}