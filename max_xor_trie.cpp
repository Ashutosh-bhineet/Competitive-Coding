#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node *temp=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(bit==0){
                if(temp->left==NULL){
                    Node* new_n=new Node();
                    temp->left=new_n;
                }
                temp=temp->left;
            }
            else{
                if(temp->right==NULL){
                    Node* new_n=new Node();
                    temp->right=new_n;
                }
                temp=temp->right;
            }
        }
    }
    int search(int a){
        Node *temp=root;
        int max=0;
        for(int i=31;i>=0;i--){
            int bit=(a>>i)&1;
            if(bit==0){
                if(temp->right!=NULL){
                    temp=temp->right;
                    max+=(1<<i);
                }
                else{
                    temp=temp->left;
                }
            }
            else{
                if(temp->left!=NULL){
                    temp=temp->left;
                    max+=(1<<i);
                }
                else{
                    temp=temp->right;
                }
            }
        }
        return max;
    }
};
int main(){
    int input[]={3,10,5,25,8,2};
    Trie t;
    for(auto x:input)
        t.insert(x);
    int ans=0;
    for(auto a:input){
        int maxXor=t.search(a);
        ans=max(maxXor,ans);
    }
    cout<<ans<<endl;
}
