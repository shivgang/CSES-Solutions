#define ll long long
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif
    
    int n;cin>>n;    
    if(n==1){
        cout<<1<<endl;
        return 0;
    }else if(n<4){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    
    int val=1;
    vector<int> A(n);
    for(int i=1;i<n;i+=2)   A[i]=val++;
    for(int i=0;i<n;i+=2)   A[i]=val++;
    
    for (int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }cout<<endl;

    return 0;
}