#define ll long long
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

// #ifndef ONLINE_JUDGE
//     freopen("../input.txt","r",stdin);
//     freopen("../output.txt","w",stdout);
// #endif
    
    ll n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n%2==1){
            n*=3;n++;
        }else
            n/=2;
        cout<<n<<" ";
    }cout<<endl;
    
    return 0;
}