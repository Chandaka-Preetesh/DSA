#include<bits/stdc++.h>
using namespace std;
class disjointSet{
    vector<int>rank;
    vector<int> size;
    vector<int> parent;
    int n;
    public:
    disjointSet(int s) {
        n=s+1;
        rank.resize(n,0);
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) {
            parent[i]=i;
        }
    }
    int findUparent(int u) {
        if(u==parent[u]) {return u;}
        return parent[u]=findUparent(parent[u]);
    }
    void unionByRank(int u,int v) {
        u=findUparent(u);
        v=findUparent(v);
        if(u==v) {return ;}
        if(rank[u]<rank[v]) {
            parent[u]=v;
        }
        else if (rank[u]>rank[v]) {
            parent[v]=u;
        }
        else {
            parent[v]=u;
            rank[u]++;
        }
    }
    void unionBySize(int u,int v) {
        u=findUparent(u);
        v=findUparent(v);
        if(u==v) {return ;}
        if(size[u]<size[v]) {
            parent[u]=v;
            size[v]=size[u]+size[v];
        }
        else {
            parent[v]=u;
            size[u]=size[u]+size[v];
        }
    }
    bool isSameComponent(int u,int v) {
        if(findUparent(u)==findUparent(v)) {return true;}
        return false;
    }
};
int main () {
    disjointSet ds(8);
    ds.unionByRank(1,3);
    ds.unionByRank(2,4);
    ds.unionByRank(4,3);
    cout<<ds.isSameComponent(2,3)<<endl;
    cout<<"parent is "<<ds.findUparent(3)<<endl;
}