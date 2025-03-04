#include<bits/stdc++.h>
using namespace std;
void inputUndirectedGraph(vector<vector<int>> &, int & ,int &);
void bfsTraversal(vector<vector<int>>&);
void bfs(vector<vector<int>>&,vector<bool>&,int );

int main () {
    int v,e;
    vector<vector<int>> graph;
    inputUndirectedGraph(graph,v,e);
    bfsTraversal(graph);

}

void inputUndirectedGraph(vector<vector<int>> & adj, int & v ,int & e ) {
    cout<<"enter the number of vertices and edges"<<endl;
    cin>>v>>e;
    adj.resize(v,vector<int> (e) );
    cout<<"start entering the graph edges"<<endl;
    for(int i=0;i<e;i++) {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    return ;
}

//bfs for all components

void bfsTraversal(vector<vector<int>> & adj) {
    int v=adj.size();
    vector<bool> vis (v,false);
    for(int i=0;i<v;i++) {
        if(!vis[i]) {bfs(adj,vis,i);}
    }
}

//for one compoent exploring level wise

void bfs(vector<vector<int>> & adj,vector<bool> & vis ,int node) {
    vis[node]=true;
    queue<int > q;
    q.push(node);
    while(!q.empty()) {
        int queue_size=q.size();
        for(int i=0;i<queue_size;i++) {
            int currNode=q.front();q.pop();
            cout<<currNode<<" ";
            for(auto it : adj[currNode]) {
                if(!vis[it]) {
                    vis[it]=true;
                    q.push(it);}
            }
        }
        cout<<endl;
    }
    return ;
}