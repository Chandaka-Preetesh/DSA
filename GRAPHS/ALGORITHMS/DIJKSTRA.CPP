#include<bits/stdc++.h>
using namespace std;
void inputWeightedGraph (vector<vector<pair<int,int> > > &,int &,int &);
void printVector(vector<int>);

// finding shortest path from one source to all other nodes in O(ElogV)


vector<int> dijkstraUsingPriorityQueue(vector<vector<pair<int, int>>> &adj, int src) {
    // using priority  queue 
    int v=adj.size();
    vector<int> dis (v,INT_MAX);
    priority_queue<pair<int,int>> pq; // to get min heap
    //make src 0 and push into pq
    dis[src]=0;
    //vis is not required evently adding of node stop automaticaly because if con to add shorter distances only
    pq.push({0,src});
    
    while(!pq.empty()) {
        
        int currNode=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        for(auto it:adj[currNode]) {
            // if get better distance to any node update and add to priority queue so it also updates it neighbours
            if(d+it.second<dis[it.first]) {
                dis[it.first]=d+it.second;
                pq.push({dis[it.first],it.first});
            }
        }
        
    }
    
    return dis;
}



vector<int> dijkstraUsingSet(vector<vector<pair<int, int>>> &adj, int src) {
    // using set 
    int v=adj.size();
    vector<int> dis (v,INT_MAX);
    set<pair<int,int>> set1;
    
    dis[src]=0;
    
    set1.insert({0,src});
    
    while(set1.size()!=0) {
        pair<int,int> p1=*set1.begin();
        int currNode=p1.second;
        int d=p1.first;
        set1.erase(set1.begin());
        for(auto it:adj[currNode]) {
            if(d+it.second<dis[it.first]) {
                dis[it.first]=d+it.second;
                if(dis[it.first]!=INT_MAX) {
                    // delete old not useful distane here only unlike priority queue
                    set1.erase({dis[it.first],it.first});
                }
                set1.insert({dis[it.first],it.first});
            }
        }
        
    }
    return dis;
}

int main () {
    int v,e;
    vector<vector<pair<int,int> > > graph;
    inputWeightedGraph(graph,v,e);
    int src;
    cout<<"enter the source"<<endl;
    cin>>src;
   // vector<int> ans=dijkstraUsingSet(graph,src);
   vector<int> ans=dijkstraUsingPriorityQueue(graph,src);
    printVector(ans);
}

void inputWeightedGraph(vector<vector<pair<int,int>>> & adj, int & v ,int & e ) {
    cout<<"enter the number of vertices and edges"<<endl;
    cin>>v>>e;
    adj.resize(v,vector<pair<int,int>> (e) );
    cout<<"start entering the graph edges src ,des and weights"<<endl;
    for(int i=0;i<e;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }
    return ;
}

void printVector(vector<int> vec) {
    cout<<endl;
    int n=vec.size();
    for(int i=0;i<n;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

