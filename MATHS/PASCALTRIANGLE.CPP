#include<bits/stdc++.h>
using namespace std;



//O(n) to get all elements in a row 

vector<int> getPascalRow(int n) {
    vector<int >row;
    row.push_back(1);
    int res=1;
    for(int i=1;i<n;i++) {
        res=(res*(n-i))/i;
        row.push_back(res);
    }
    return row;
}


//genearate full pascal triangle O(n^2)
// values row,column is row-1 C column -1

vector<vector<int>> generatePascal(int numRows) {
    vector<vector<int>>ans(numRows);
    for(int i=0;i<numRows;i++) {
        ans[i].resize(i+1,1);
        for(int j=1;j<i;j++) {
            ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
    }
    return ans;
}





//O(r) 

int getParticularElement(int n,int r) {
    //is n-1cr-1
    int res=1;
    for(int i=1;i<r;i++) {
        res=(res*(n-i))/i;
    }
    return res;
}


int main () {
    /*
    get particular row

    int n;
    cout<<"enter the rquiered pascal row"<<endl;
    cin>>n;
    vector<int> ans=getPascalRow(n);
    for(auto it:ans) {
        cout<<it<<" ";
    }
    */
    /*
    int n,r;
    cout<<"enter the row and column s"<<endl;
    cin>>n>>r;
    cout<<"the anser is "<<getParticularElement(n,r);
    */
    int n;
    cout<<"enter number of rows requiered for pascal triange"<<endl;
    cin>>n;
    vector<vector<int>> ans=generatePascal(n);
    for(int i=0;i<ans.size();i++) {
        for(int j=0;j<ans[i].size();j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

