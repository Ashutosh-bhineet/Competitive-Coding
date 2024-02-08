#include <bits/stdc++.h>
    using namespace std;
     
     
    class Graph{
    	//Adj List (unweighted)
    	int n;
    	vector<int> * adjList; //Pointer to an array of vector 
    public:
    	Graph(int n){
    		this->n = n;
    		adjList = new vector<int>[n];
    	}
     
    	void addEdge(int u,int v,bool directed=true){
     
    		if(directed){
    			adjList[u].push_back(v);
    		}
    		else{
    			adjList[u].push_back(v);
    			adjList[v].push_back(u);
    		}
    	}
     
    	void printAdjList(){
    		// code to print adj list // 
    		for(int i=0;i<n;i++){
    			cout<<i<<" : ";
    			for(auto nbr: adjList[i]){
    				cout<<nbr<<",";
    			}
    			cout<<endl;
    		}
    	}
     
    	void bfs(int s){
    		vector<bool> visited(n,false);
    		queue<int> q;
     
    		q.push(s);
    		visited[s] = true;
     
    		while(!q.empty()){
    			int f = q.front();
    			cout<<f<<" ";
    			q.pop();
     
    			for(auto nbr:adjList[f]){
    				if(!visited[nbr]){
    					visited[nbr] = true;
    					q.push(nbr);
    				}
    			}
    		}
    	}
     
    	void bfsSSSP(int s){
    		vector<bool> visited(n,false);
    		vector<int> dist(n,INT_MAX);
     
    		queue<int> q;
     
    		q.push(s);
    		visited[s] = true;
    		dist[s] = 0;
     
    		while(!q.empty()){
    			int f = q.front();
    			cout<<f<<" ";
    			q.pop();
     
    			for(auto nbr:adjList[f]){
    				if(!visited[nbr]){
    					dist[nbr] = dist[f] + 1 ;
    					visited[nbr] = true;
    					q.push(nbr);
    				}
    			}
    		}
    		//Dist Vector
    		for(int i=0;i<n; i++){
    			cout<<"Node "<<i<<" Dist "<<dist[i]<<endl;
    		}
     
    	}
    	//BFS Shortest Path
    	void bfsShortestPath(int s,int d){
    		//Modify the function to get the path 12.25
    		vector<bool> visited(n,false);
    		vector<int> dist(n,INT_MAX);
    		vector<int> parent(n,-1);
     
    		queue<int> q;
     
    		q.push(s);
    		visited[s] = true;
    		dist[s] = 0;
     
    		while(!q.empty()){
    			int f = q.front();
    			cout<<f<<" ";
    			q.pop();
     
    			for(auto nbr:adjList[f]){
    				if(!visited[nbr]){
    					dist[nbr] = dist[f] + 1 ;
    					parent[nbr] = f;
     
    					visited[nbr] = true;
    					q.push(nbr);
    				}
    			}
    		}
    		//dest to source trace back the path 
    		int temp = d;
    		vector<int> path;
    		path.push_back(temp);
    		cout<<endl;
     
    		while(parent[temp]!=-1){
    			temp = parent[temp];
    			path.push_back(temp);
    		}
    		reverse(path.begin(),path.end());
    		for(auto node:path){
    			cout<<node<<",";
    		}
    	}
    };
     
    int main(){
     
    	Graph g(6);
    	g.addEdge(0,1,false);
    	g.addEdge(0,2,false);
    	g.addEdge(1,2,false);
    	g.addEdge(1,3,false);
    	g.addEdge(2,5,false);
    	g.addEdge(3,5,false);
    	g.addEdge(3,4,false);
     
    	//g.bfs(0);
    	g.bfsSSSP(0);
     
     
    	//Print the shortest path from source to destination 
    	cout<<endl;
    	cout<<"Shortest Path "<<endl;
    	g.bfsShortestPath(0,5); 
     
    	// N 
    	int nodes;
    	cin>>nodes;
    	//read snakes 
     
     
    	//read ladders
     
    	//create the graph 
     
    	addEdge();
     
     
     
     
     
    	//g.printAdjList();
    }