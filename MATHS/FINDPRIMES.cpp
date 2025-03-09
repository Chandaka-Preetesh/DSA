#include<bits/stdc++.h>
using namespace std;

// sevieEarthonas algo to find all primes from 1 to n in O(nlog(logsqrt(n)))
    vector<bool> seiveEarthotanes(int n) {
        //getting a prime and marking all it multiples non prime 
        vector<bool> isPrime(n+1,true);
        isPrime[0]=false;isPrime[1]=false;
        for(int i=2;i*i<=n;i++) { //only till here prime factor can come 
            if(isPrime[i]==true) {
                // i*i because all are previosly marked by other previously
            for(int j=i*i;j<=n;j=j+i) {
                isPrime[j]=false;
            }
            }
        }
        return isPrime;
    }

    // to find prime in range l to r use contraints are high and small difference between l and r .
    vector<bool> segmentedSeive(int left,int right) {
        // find all prime from 2 sqrt(r)
        vector<bool> isPrime=seiveEarthotanes( sqrt(right) );
        vector<bool> segment (right-left+1,true);
        for(int i=2;i*i<=right;i++) {
            if(isPrime[i]) {
                //if i*i less then ( (left+i-1)/i  )*i find position of postion of first divisorin in segment
                for(int j=max(i*i,(left+i-1)/i*i);j<=right;j=j+i) {
                    segment[j-left]=false;
                }
            }
        }
        if(left==1) {segment[0]=false;}
        return segment;
    }

// to verify a number is prime or not in O(n^1/2)
// reason a divisor to a numbe can exit is atmost n^1/2 to checking till there enough
bool isPrime(int n) {
    if(n==1) {return false;}
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {return false;}
    }
    return true;
}


int main () {

    /*
    int n;
    cout<<"enter a number "<<endl;
    cin>>n;
    cout<<isPrime(n)<<endl;
    */
    /*
    int n;
    cout<<"enter the number of primes till needed" <<endl;
    cin>>n;
    vector<bool> ans=seiveEarthotanes(n);
    cout<<"the primes are"<<endl;
    for(int i=0;i<ans.size();i++) {
        if(ans[i]) {
            cout<<i<<" ";
        }
    } 
    cout<<endl;
    */
    int l,r;
    cout<<"enter the range "<<endl;
    cin>>l>>r;
    vector<bool> ans=segmentedSeive(l,r);
    cout<<"the primes are"<<endl;
    for(int i=0;i<ans.size();i++) {
        if(ans[i]) {
            cout<<i+l<<" ";
        }
    } 
    cout<<endl;
}
