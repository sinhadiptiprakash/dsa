#include<bits/stdc++.h>
using namespace std;
bool is_a_rotation(string str1,string str2){
    /* Check if sizes of two strings are same */
    if (str1.length() != str2.length())
            return false;
    string temp = str1 + str1; 
    return (temp.find(str2) != string::npos);
}
int main(){
    string s,s2;
    cin>>s>>s2;
    cout<<is_a_rotation(s,s2)<<endl;
    return 0;
}

