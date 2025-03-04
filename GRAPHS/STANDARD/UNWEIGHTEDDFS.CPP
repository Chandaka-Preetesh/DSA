#include<bits/stdc++.h>
using namespace std;
void inputUndirectedGraph(vector<vector<int>> &, int & ,int &);
void dfsTraversal(vector<vector<int>>&);
void dfs(vector<vector<int>>&,vector<bool>&,int );

int main () {
    int v,e;
    vector<vector<int>> graph;
    // to take input
    inputUndirectedGraph(graph,v,e);
    //
    dfsTraversal(graph);

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

//dfs for all components of graph

void dfsTraversal(vector<vector<int>> & adj) {
    int v=adj.size();
    vector<bool> vis (v,false);
    for(int i=0;i<v;i++) {
        if(!vis[i]) {dfs(adj,vis,i);}
    }
}

//dfs call exploring negihbour depth first and after return exploring other neighrbours

void dfs(vector<vector<int>> & adj,vector<bool> & vis ,int node) {
    vis[node]=true;
    cout<<node<<" ";
    for(auto it :adj[node] ) {
        if(!vis[it]) {dfs(adj,vis,it);}
    }
    return ;
}