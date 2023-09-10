#define ll long long
#define li long int
#include<iostream>
#include<bits/stdc++.h>
using namespace std;    
int main(){

#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif
    
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;

        ll ans;
        if(x==y){
            ans=x*(y-1)+1;
        }
        else if(x>y){
            if(x%2==0)
                ans=(x*x)-y+1;
            else
                ans=x*(x-1) - (x-1 - y);            
        }else{
            if(y%2!=0)
                ans=(y*y)-x+1;
            else
                ans=y*(y-1) - (y-1 - x);
        }
        cout<<ans<<endl;
    }

    return 0;
}















// TLE
// #define ll long long
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;    
// int main(){

// #ifndef ONLINE_JUDGE
//     freopen("../input.txt","r",stdin);
//     freopen("../output.txt","w",stdout);
// #endif
    
//     int t;
//     cin>>t;
//     map<pair<int,int>,int> map;
//     while(t--){
//         int x,y;
//         cin>>x>>y;
//         x--;y--;
//         if(map.find({x,y})!=map.end()){
//             cout<<map[{x,y}]<<endl;
//             continue;
//         }
//         int diagonalInd=max(x,y),diagonalVal=1;
//         for(int i=1,count=2;i<=diagonalInd;i++,count+=2)
//             diagonalVal+=count;

//         int numberofMoves=abs(x-diagonalInd)+abs(y-diagonalInd);

//         int finalValue=-1;
//         if(x==y)    
//             finalValue=diagonalVal;
//         if(x<y){
//             if( (x%2==0) && (y%2==0) )              // taking 2 4 as example  
//                 finalValue=diagonalVal+numberofMoves;             // here both even 
//             else if( (x%2==0) && (y%2!=0) )                // taking 2 3 as example  
//                 finalValue=diagonalVal-numberofMoves;             // here only one even ie first
//             else if( (x%2!=0) && (y%2==0) )                // taking 1 4 as example  
//                 finalValue=diagonalVal+numberofMoves;             // here only one even ie second
//             else                                          // when neither even 1 3
//                 finalValue=diagonalVal-numberofMoves;
//         }
//         else if(x>y){
//             if( (x%2==0) && (y%2==0) )               // taking 4 2 as example  
//                 finalValue=diagonalVal-numberofMoves;             // here both even
//             else if( (x%2==0) && (y%2!=0) )               // taking 3 2 as example  
//                 finalValue=diagonalVal-numberofMoves;             // here only one even ie second
//             else if( (x%2!=0) && (y%2==0) )               // taking 1 4 as example  
//                 finalValue=diagonalVal+numberofMoves;             // here only one even ie first
//             else                                        // when neither even 3 1
//                 finalValue=diagonalVal+numberofMoves;
//         } 
//         map[{x,y}]=finalValue;
//         cout<<finalValue<<endl;

//     }

//     return 0;
// }