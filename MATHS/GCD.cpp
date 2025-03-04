#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b) {
    while(a>0 && b>0) {
        if(a>b) {a=a%b;}
        else {b=b%a;}
    }
    return a!=0? a:b; 
}

// stl
//  __gcd(a,b) 
// __hcf(a,b)

//properties 

// gcd(a,b)==gcd(a%b,b) if a>b vicecerse and both a,b greater than 0
//hcf*lcm==a*b
//   gcd*lcm==a*b

int main () {
    int a,b;
    cin>>a>>b;
    cout<<"the gcd is "<<gcd(a,b)<<endl;
}


//time complexity O(log(n) base phi)