#include<bits/stdc++.h>
using namespace std;
//approach using stack
string remove_duplicates(string s) {
    if(s.empty())return "";
    stack<char> st;
    string res="";
    int n=s.size();
    st.push(s[0]);
    for(int i=1;i<n;i++){
        if(!st.empty() && s[i]==st.top())
            st.pop();
        else st.push(s[i]);
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    string str;
    cin>>str;
    cout<<remove_duplicates(str)<<endl;
    return 0;
}