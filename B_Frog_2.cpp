// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int k;
int h[N];
int dp[N];
 int func(int i){
     if(i==0) return i;
     if(dp[i]!=-1) return dp[i];
     int cost=INT_MAX;
     for(int j=1;j<=k;j++){
     if(i-j>=0)
     cost=min(cost,func(i-j)+abs(h[i]-h[i-j]));
     }

    return dp[i]=cost;
 }  
signed main() {
        memset(dp,-1,sizeof(dp));
         int n;
         cin>>n>>k;
         for(int i=0;i<n;i++){
            cin>>h[i];
         }
    cout<<func(n-1)<<endl;
      
}

