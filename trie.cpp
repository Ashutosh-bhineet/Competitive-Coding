#include<bits/stdc++.h>
using namespace std;
#define int long long int
class Node{
    public:
    char data;
    unordered_map<char,Node*> children;
    bool isTerminal;
    Node(char d){
        data=d;
        isTerminal=false;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node('\0');
    }
    void addWord(string word){
        Node* temp=root;
        for(auto ch:word){
            if(temp->children.count(ch)==0){
                Node* child=new Node(ch);
                temp->children[ch]=child;
                
                temp=child;
            }
            else{
                temp=temp->children[ch];
            }
        }
        temp->isTerminal=true;
    }
    bool search(string query){
        Node* temp=root;
        for(auto ch: query){
            if(temp->children.count(ch)){
                temp=temp->children[ch];
            }
            else{
                return false;
            }
        }
        return temp->isTerminal;
    }
};
int32_t	 main(){
    Trie t;
    string words[]={"apple","ape","batman","new","news","appy"};
    for(auto w:words){
        t.addWord(w);
    }
    string query;
    cin>>query;
    cout<<t.search(query);
}