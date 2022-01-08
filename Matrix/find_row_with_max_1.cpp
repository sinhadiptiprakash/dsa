#include<bits/stdc++.h>
using namespace std;
//below binary search returns the position of the first one in a row
int binary_search(vector<int> &row,int row_size){
    int low=0,high=row_size-1,mid;
    // we initialize the res as the row_size as there may me a case when all the row elements are 0,
    // then in that case we should return row_size because we don't find any one
    // the case when all elements are 1 is already handled by the rest of the code
    int res=row.size();
    while(low<=high){
        mid=low+(high-low)/2;
        // if the mid is 1 then we should go for finding a lower index than mid 
        if(row[mid]==1){
            res=mid;
            high=mid-1;
        }
        // otherwise if the row[mid]==0 we should go to the right side of the array as we are looking for 1
        else if(row[mid]==0)low=mid+1;
    }
    return res;
}
//below is the main function for getting the row with maximum no. of ones using above binary search function
int row_with_max_one_binary_search(vector<vector<int>> &matrix){
    int num_of_row=matrix.size();
    int num_of_col=matrix[0].size();
    int max_ones=INT_MIN;
    int ones_in_this_row;
    int res_row;
    for(int i=0;i<num_of_row;i++){
        //getting the no. of ones in this ith row
        ones_in_this_row=num_of_col-binary_search(matrix[i],num_of_col);
        //if the no. of ones in this row is greater than no. of maximum ones so far 
        // we should update the max_ones as well as res_row to this row
        if(ones_in_this_row>max_ones){
            res_row=i;
            max_ones=ones_in_this_row;
        }
    }
    return res_row;
}
/*
The above solution can be optimized further. 
Instead of doing binary search in every row, we first check whether the row has more 1s than max so far. 
If the row has more 1s, then only count 1s in the row. 
Also, to count 1s in a row, we don’t do binary search in complete row, 
we do search in before the index of last max. 
*/
int row_with_max_ones_binary_search_optimized(vector<vector<int>> matrix){
    int num_of_rows=matrix.size();
    int num_of_cols=matrix[0].size();
    int max_ones=INT_MIN,ones_in_this_row;
    int res_row,index;
    // first we get the no. of ones in the first row and initilize all the above variables
    // getting the index of first one in the first row
    index=binary_search(matrix[0],num_of_cols);
    max_ones=num_of_cols-index;
    res_row=0;
    for(int i=1;i<num_of_rows;i++){
        // if the index of first one of the previous row is not out of bound 
        // and there is a one at the same index+1 postion in the curent row
        // then we can say that this row has more ones than before
        if(index!=num_of_cols && matrix[i][num_of_cols-index-1]==1){
            //here is an optimization we are decreasing the search space by decreasing the high
            index=binary_search(matrix[i],num_of_cols-index);
            ones_in_this_row=num_of_cols-index;
            if(ones_in_this_row>max_ones){
                res_row=i;
                max_ones=ones_in_this_row;
            }
        }
        else{
            index=binary_search(matrix[i],num_of_cols);
        }
    }
    return res_row;
}
/*
Following method works in O(m+n) time complexity in worst case. 
Step1: Get the index of first (or leftmost) 1 in the first row.
Step2: Do following for every row after the first row 
…IF the element on left of previous leftmost 1 is 0, ignore this row. 
…ELSE Move left until a 0 is found. Update the leftmost index to this index and max_row_index to be the current row.
The time complexity is O(m+n) because we can possibly go as far left as we came ahead in the first step.
*/
int row_with_max_ones_efficient(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = -1;
    int i = 0, j = m - 1;
    while ((i < n) && (j >= 0))
    {
        if (matrix[i][j] == 1)
        {
            ans = i;
            j--;
        }
        if (matrix[i][j] == 0)
        {
            i++;
        }
    }
    return ans;
}
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>> matrix(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<row_with_max_ones_binary_search_optimized(matrix)<<endl;
    return 0;
}