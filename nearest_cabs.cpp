#include <bits/stdc++.h>
using namespace std;
class Cabs{
    public:
    string name;
    int x;
    int y;
    Cabs(string name,int x,int y){
        this->name=name;
        this->x=x;
        this->y=y;
    }
};
class CabCompare{
    public:
    bool operator()(Cabs a,Cabs b){
        return abs(a.x+a.y)>(b.x+b.y);
    }
};
int main(){
    int n;
    cin>>n;
    priority_queue<Cabs,vector<Cabs>,CabCompare> p;
    for(int i=0;i<n;i++){
        string name;
        int x,y;
        cin>>name>>x>>y;
        Cabs c(name,x,y);
        p.push(c);
    }
    int k;
    cin>>k;
    while(k--){
        cout<<p.top().name<<endl;
        p.pop();
    }
}