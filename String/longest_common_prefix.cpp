#include<bits/stdc++.h>
using namespace std;
//vertical scanning method
string longest_common_prefix(vector<string>& strs){
    int max_len,min_len=INT_MAX;
    //getting the min_length of all the strings because the maximum_length of common prefix cant be greater than min_length
    for(string st:strs){
        int l=st.length();
        if(l<min_len)
            min_len=l;
    }
    max_len=0;
    //i is for indexing the characters of a string
    for(int i=0;i<min_len;i++){
        bool flg=true;
        // j is for indexing the strings
        for(int j=1;j<strs.size();j++){
            // if ith index of the curent(jth) string is not same as the previous then we should stop searching
            if(strs[j][i]!=strs[j-1][i]){
                flg=false;
                break;
            }
        }
        if(flg)//if we are getting match of character in all string 
            max_len++;
        else break;
    }
    //longest common prefix string would be the substring starting from 0 to max_len-1
    return strs[0].substr(0,max_len);
}//time complexity O(S) where S is the total number of characters in all strings, space complexity O(1)
//we can implement it using a trie data structure as well
int main(){
    vector<string> strs={"flower","flow","flight"};
    cout<<longest_common_prefix(strs)<<endl;
    return 0;
}