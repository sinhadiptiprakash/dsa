#include<bits/stdc++.h>
using namespace std;
struct BSTNode{
    int data;
    BSTNode *left;
    BSTNode *right;
    BSTNode(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
void insert(BSTNode **root,int d){
    if(*root==NULL){
        *root=new BSTNode(d);
    }
    else{
        if(d<(*root)->data){
            insert(&(*root)->left,d);
        }
        else{
            insert(&(*root)->right,d);
        }
    }
}
int find_a_value_in_bst(BSTNode *root,int d){
    if(root==NULL)
        return 0;
    
    else{
        if(root->data==d)
            return 1;
        
        else{
            if(root->data<d)
                return find_a_value_in_bst(root->right,d);
              
            else
                return find_a_value_in_bst(root->left,d);
            
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    BSTNode *root=NULL;
    for(int i=0;i<n;i++){
        insert(&root,a[i]);
    }
    int d;
    cin>>d;
    cout<<find_a_value_in_bst(root,d)<<endl;
    return 0;
}