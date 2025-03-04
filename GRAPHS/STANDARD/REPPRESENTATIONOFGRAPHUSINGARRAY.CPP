#include<iostream>
using namespace std;
int main() {
    int n,m;
    cout<<"enter number of vertices and edges "<<endl;
    cin>>n>>m;
    // 1 based indexing
    int arr[n+1][n+1]={0};
    cout<<"enter first to second and weihgt"<<endl;
    for(int i=0;i<m;i++) {
        int a,b,w;
        cin>>a>>b>>w;
        arr[a][b]=w;
        arr[b][a]=w; //if undirected
    }
    //g++ $fileName -o a && ./a.exe
    cout<<"the adjacency matrix is "<<endl;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}