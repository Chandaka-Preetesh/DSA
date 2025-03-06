#include<bits/stdc++.h>
using namespace std;

// in   a dag atleast one zero degree is guaranteed
// if current graph is dag then all subgraphs are also dag so we keep on geting 0 degree vertices 

// if stoped somewhere means there is a cylce 

// if u -> v exist then u should before v this topological ordering 

vector<int> KhansAlgo(vector<vector<int>>& adj) {
    
    vector<int > ans;
    int v=adj.size();
    vector<int> indegree (v,0);
    for(int i=0;i<v;i++) {
        for(auto it:adj[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++) {
        if(indegree[i]==0) {q.push(i);}
    }
    while(!q.empty()) {
        int curr=q.front();q.pop();
        ans.push_back(curr);
        for(auto it:adj[curr]) {
                indegree[it]--;
            if(indegree[it]==0) {q.push(it);}
        }
    }
    return ans;
}

int main() {
      int n,m;
    cout<<"enter number of vertices and edges "<<endl;
    cin>>n>>m;
    vector <vector<int>> graph(n);
    cout<<" enter first to second and wieght"<<endl;
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }

    vector<int > ans=KhansAlgo(graph);
    cout<<endl;
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}

//via dfs 

void dfs(vector<vector<int>>& adj,vector<bool> & vis,vector<int> & ans,int node) {
    vis[node]=true;
    for(auto it:adj[node] ) {
        if(!vis[it]) {dfs(adj,vis,ans,it);}
    }
    ans.push_back(node);
}

// storing node after dfs means all its neighers are visited priorly 
// meaning it push after all it adjacent nodes gauranted
// reverseing will node is prior to all neighbours
//it the requiered conditon for topological sort 

vector<int> topologicalSort(vector<vector<int>>& adj) {
    vector<int> ans;
    int v=adj.size();
    vector<bool> vis (v,false);
    for(int i=0;i<v;i++) {
        if(!vis[i]) {
            dfs(adj,vis,ans,i);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}