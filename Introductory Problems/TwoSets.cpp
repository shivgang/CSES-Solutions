#define ll long long
#define li long int
#include<iostream>
#include<bits/stdc++.h>
using namespace std;    

bool findnums(ll sum,ll index,vector<ll> &ans){
    if(sum==0)  return true;
    if(index==0)  return false;

    if(findnums(sum,index-1,ans))
        return true;

    ans.push_back(index);
    if(findnums(sum-index,index-1,ans))
        return true;
    ans.pop_back(); 
    
    return false;
}
int main(){

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif
    
    ll n;
    cin>>n;
    
    ll sum = n * (n + 1) / 2 ;
    if(sum%2==1){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        vector<ll> first,second;
        if(n%2==0){ // n is even
            
            for(ll i=1,j=n;i<j;){
                if(i%2==1){
                    first.push_back(i++);
                    first.push_back(j--);
                }else{
                    second.push_back(i++);
                    second.push_back(j--);
                }   
            }
        }else{

            for(int i=1,j=n-1;i<j;){
                if(i%2==1){
                    first.push_back(i++);
                    first.push_back(j--);
                }else{
                    second.push_back(i++);
                    second.push_back(j--);
                }   
            }
            
            if(first.size() > second.size())
                second.push_back(n);
            else
                first.push_back(n);
            
        }
        cout<<first.size()<<endl;
        for(auto x:first){
            cout<<x<<" ";
        }cout<<endl;
        cout<<second.size()<<endl;
        for(auto x:second){
            cout<<x<<" ";
        }cout<<endl;
    }
    
    return 0;
}
    
// #define ll long long
// #define li long int
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;    

// bool findnums(ll sum,ll index,vector<ll> &ans){
//     if(sum==0)  return true;
//     if(index==0)  return false;

//     if(findnums(sum,index-1,ans))
//         return true;

//     ans.push_back(index);
//     if(findnums(sum-index,index-1,ans))
//         return true;
//     ans.pop_back(); 
    
//     return false;
// }
// int main(){

// #ifndef ONLINE_JUDGE
//     freopen("../input.txt","r",stdin);
//     freopen("../output.txt","w",stdout);
// #endif
    
//     ll n;
//     cin>>n;
    
//     ll sum = n * (n + 1) / 2 ;
//     if(sum%2==1){
//         cout<<"NO"<<endl;
//     }else{
//         cout<<"YES"<<endl;

//         vector<ll> first,second; 
//         findnums(sum/2,n,first);
//         reverse(first.begin(),first.end());

//         cout<<first.size()<<endl;
//         for(auto x:first){
//             cout<<x<<" ";
//         }cout<<endl;

//         ll count=1;
//         for(ll i=0;i<first.size();i++){
//             if(first[i]==count){
//                 count++;
//                 continue;
//             }else{
//                 while(first[i]!=count){
//                     cout<<first[i]<<" "<<count<<endl;
//                     second.push_back(count++);
//                 }i--;
//             }
//         }
//         while(count<=n)
//             second.push_back(count++);
//         cout<<second.size()<<endl;
//         for(auto x:second){
//             cout<<x<<" ";
//         }cout<<endl;
        
//     }

//     // for(int i=1;i<=n;i++){
//     //     cout<<i<<" -> "<< i * (i+1) /2 <<endl;
//     // }
//     return 0;
// }
    