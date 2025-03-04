#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<pair<int,int>>> &);
vector<int>  bfsOfGraph(vector<vector<pair<int,int>>> &);
void dfs(int ,int [],vector<vector<pair<int,int>>> & ,vector<int> &);
vector<int> dfsOfGraph(vector<vector<pair<int,int>>> &);
int main() {
      int n,m;
    cout<<"enter number of vertices and edges "<<endl;
    cin>>n>>m;
    // one based indexing 
    vector <vector<pair<int,int>>> graph(n+1);
    cout<<" enter first to second and wieght"<<endl;
    for(int i=0;i<m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
print(graph);  
    vector<int> bfs =bfsOfGraph(graph);
    cout<<endl<<"the bfs traversal is "<<endl;
    for(auto i: bfs) {
        cout<<i<<" ";
    }
    cout<<endl<<"the dfs traversal is "<<endl;
    int vis[n+1]={0};
    vector<int> ans =dfsOfGraph(graph);
    for(auto i: ans) {
        cout<<i<<" ";
    }
    return 0;
}
void print(vector<vector<pair<int,int>>> &graph) {
    int n=graph.size();
     cout<<endl<<"the graph is "<<endl;
    for(int i=1;i<n;i++) {
        cout<<i<<" = { ";
        for(int j=0;j<graph[i].size();j++) {
            cout<<" {"<<graph[i][j].first<<","<<graph[i][j].second<<"}"<<"  ";
        }
        cout<<" }";
         cout<<endl;
    }
    return;
}
 vector<int> bfsOfGraph(vector<vector<pair<int,int>>> & adj) {
        int n=adj.size();
        int vis[n+1]={0};
        queue<int> q;
        vis[1]=1;q.push(1);
        vector<int> bfs;
        while(!q.empty()) {
            int curr=q.front();q.pop();
            bfs.push_back(curr);
            for(auto i:adj[curr]) {
                if(!vis[i.first]) {
                    vis[i.first]=1;q.push(i.first);
                }
            }
        }
        return bfs;
        }
        
        void dfs(int start,int vis[],vector<vector<pair<int,int>>> &adj,vector<int> &ans) {
        vis[start]=1;
        ans.push_back(start);
        for(auto i:adj[start]) {
            if(!vis[i.first]) {
                dfs(i.first,vis,adj,ans);
            }
        }
        return ;
    }
    vector<int> dfsOfGraph(vector<vector<pair<int,int>>> &adj) {
        // Code here
        int n=adj.size();
        int vis[n+1]={0};vector<int>ans;
        int start=1;
        dfs(start,vis,adj,ans);
        return ans;
    }