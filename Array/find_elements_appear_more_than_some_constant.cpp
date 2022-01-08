#include<bits/stdc++.h>
using namespace std;
//below function prints elements appear more than n/k times using hashing
// for every element count its frequency,if the frequency is greater than n/k print it
void find_elements_appear_more_than_some_constant(int arr[],int n,int k){
    int x = n / k;
    // unordered_map initialization
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    // Traversing the map
    for(auto i : freq){ 
        // Checking if value of a key-value pair
        // is greater than x (where x=n/k)
        if (i.second > x){
            // Print the key of whose value
            // is greater than x
            cout << i.first <<' ';
        }
    }
    cout<<endl;
}
int main(){
    int arr1[] = { 4, 5, 6, 7, 8, 4, 4 };
    int size = sizeof(arr1) / sizeof(arr1[0]);
    find_elements_appear_more_than_some_constant(arr1,size,3);
    int arr2[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
    int n = sizeof(arr2) / sizeof(arr2[0]);
    int k = 4;
    find_elements_appear_more_than_some_constant(arr2,n,k);
    return 0;
}