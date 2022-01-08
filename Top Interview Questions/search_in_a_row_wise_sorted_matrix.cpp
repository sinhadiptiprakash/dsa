#include <bits/stdc++.h>
using namespace std;
//below is the approach which uses binary_search in each row to find the element
bool binary_search(vector<int> row, int target)
{
    int low = 0, high = row.size() - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (row[mid] == target)
            return true;
        else if (row[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        if (binary_search(matrix[i], target))
            return true;
    }
    return false;
} //time complexity is O(Row*log(col))
//below is the effiecient approach which uses binary seach in the whole matrix
// for doing so we convert virtually the 2d array into a 1d array and appty binary-search in that 1d array
// for that we need to map 1d array co-ordiantes into 2d array co-ordiantes
// below function converts a 1d co-ordinates into a 2d cordinates
pair<int, int> get_coordinates(int index, int row, int col)
{
    int r, c;
    r = index / col;
    c = index - (r * col);
    return {r, c};
}
//returns row,col of the target item
pair<int, int> binary_search_in_row_wise_sorted_matrix(vector<vector<int>> &matrix, int target)
{
    // low points to 0th cell and high points to the bottom right-most cell
    int low = 0, high = matrix.size() * matrix[0].size() - 1, mid;
    //no of rows
    int row = matrix.size();
    // no. of colums
    int col = matrix[0].size();
    // r,c for storing the mapped 2d corodinates
    int r, c;
    pair<int, int> coordinates;
    // from here bianary search begins
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        // get the mapping of the 1d coordinates
        coordinates = get_coordinates(mid, row, col);
        r = coordinates.first, c = coordinates.second;
        // if the middle elemet is the target return its coordiantes
        if (matrix[r][c] == target)
            return {r, c};
        // if the middle element is smaller than target we increase low=mid+1
        else if (matrix[r][c] < target)
            low = mid + 1;
        //else we decrease high=mid-1
        else
            high = mid - 1;
    }
    return {-1, -1};
} // time complexity O(log(row*col))
//below is the another approach
// we start comparing from the right-most elemet of the 1st row
// if the curent element is the target itself return its coordinates
// if curent element is less than the target then we should go down
//i.e. increase the row as matrix is row-wise sorted, so the bigger elements will be below curent element
// if curent element is greater than the target then we should go down
//i.e. decrease the row as matrix is row-wise sorted, so the smaller elements will be in the left side of the curent element
pair<int, int> search_in_row_wise_sorted_matrix(vector<vector<int>> &matrix, int target)
{
    //start from the right-most element of the 1st row
    int i = 0, j = matrix[0].size() - 1;
    //if i and j is within the range of the matrix
    while (i < matrix.size() && j >= 0)
    {
        // if the curent element is the target return its location
        if (matrix[i][j] == target)
            return {i, j};
        // if the curent element is less than the target then we should go down
        if (matrix[i][j] < target)
            i++;
        // if the curent element is greater than the target then we should go left
        else
            j--;
    }
    return {-1, -1};
} //time complexity is O(row+col)
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
    int target = 16;
    pair<int, int> res = search_in_row_wise_sorted_matrix(matrix, target);
    cout << res.first << ' ' << res.second << endl;
    return 0;
}