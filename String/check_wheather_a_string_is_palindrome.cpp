#include<bits/stdc++.h>
using namespace std;
bool is_palindrome(string s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++,j--;
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    cout<<is_palindrome(s)<<endl;
    return 0;
}