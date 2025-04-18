#include<bits/stdc++.h>
using namespace std;

class FenwickTree {
    public:
    vector<int> fen;
    void createTree(vector<int> arr) {
        int size=arr.size();
        fen.resize(size+1,0);
        for(int i=1;i<=size;i++) {
         //update(i+1,arr[i]) n logn 
         fen[i]=fen[i]+arr[i-1];
         int j=i+(i&-i); //O(n)
         if(j<=size) {fen[j]=fen[j]+fen[i];}
        }
    }
    void update (int i,int n) {
        int size=fen.size();
        while(i<size) {
            fen[i]=fen[i]+n;
            i=i+(i&-i);
        }
    }

    int sum (int i) {
        int sum=0;
        while(i>0) {
            sum=sum+fen[i];
            i=i-(i&-i);
        }
        return sum;
    }
    int rangeSum(int l,int r) {
        return sum(r)-sum(l-1);
    }
};

void printVector(vector<int> vec) {
    cout<<endl;
    int n=vec.size();
    for(int i=0;i<n;i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

int main () {
    int n;
    cout<<"enter n "<<endl;
    cin>>n;
    vector<int> arr (n);
    cout<<"start entering "<<endl;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    FenwickTree obj;
    obj.createTree(arr);
   printVector(obj.fen);
   cout<<obj.rangeSum(1,3)<<endl;
   cout<<obj.rangeSum(1,4)<<endl;
   cout<<obj.rangeSum(3,6)<<endl;
}