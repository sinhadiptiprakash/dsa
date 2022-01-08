#include <bits/stdc++.h>
using namespace std;
//for algorithm watch Tech Dose video 
//for code refer Karumanchi book

//below is the function returns the prefix table of the pattern to avoid repeated searching in pattern
vector<int> prefix_table(string pattern){
    int n=pattern.size();
    vector<int> table(n);
    table[0]=0;
    int i=1,j=0;
    while(i<n){
        if(pattern[i]==pattern[j]){
            table[i]=j+1;
            i++;
            j++;
        }
        else if(j>0){
            j=table[j-1];
        }
        else{
            table[i]=0;
            i++;
        }
    }
    return table;
}
//now we will be using the above prefix table to match the strings
vector<int> KMP(string text,string pattern){
    int n=text.size();
    int m=pattern.size();
    vector<int> result;
    int i=0,j=0;
    vector<int> prefix=prefix_table(pattern);
    while(i<n){
        if(text[i]==pattern[j]){
            //if we have compared all the characters of this window so far we store the result
            if(j==m-1){
                result.push_back(i-j);
                i++;
                j=prefix[j-1];
            }
            else{
                i++;
                j++;
            }
        }
        else if(j>0)
            j=prefix[j-1];
        else i++;
    }
    return result;
}
int main(){
    string text,pattern;
    cin>>text>>pattern;
    auto res=KMP(text,pattern);
    for(int i:res){
        cout<<i<<' ';
    }
    cout<<'\n';
    return 0;
}