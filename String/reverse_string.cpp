#include<bits/stdc++.h>
using namespace std;
void reverse_string(string& s) {
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i++],s[j--]);
        }
}
int main(){
    string s;
    cin>>s;
    reverse_string(s);
    cout<<s<<endl;
    return 0;
}