#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    public:
    unordered_map<T,vector<pair<T,int>>> edges;
    void addEdge(T s,T v,int weight,bool dir=true){
        if(dir==true)
        edges[s].push_back({v,weight});
        else{
        edges[s].push_back({v,weight});
        edges[v].push_back({s,weight});
        }
    }
    void printAdjList(){
        for(auto it:edges){
            cout<<it.first<<" -> ";
            for(auto e:it.second){
                cout<<"{"<<e.first<<","<<e.second<<"}"<<",";
            }
            cout<<endl;
        }
    }
    void bfs(string source){
        unordered_map<string,bool> v;
        queue<string> q;
        q.push(source);
        v[source]=true;
        while(!q.empty()){
            string s=q.front();
            q.pop();
            cout<<s<<" ";
            for(auto adj:edges){
                if(v.count(adj.first)==0){
                    v[adj.first]=true;
                    q.push(adj.first);
                }
            }
        }
    }
    
};
int main(){
    Graph<string> g;
    g.addEdge("Delhi","Amritsar",5,false);
    g.addEdge("Delhi","Mumbai",8,false);
    g.printAdjList();
    g.bfs("Delhi");
}