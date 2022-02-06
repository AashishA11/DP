// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int wt[105];
int val[105]; 
int dp[105][N];
int Knapsack(int ind,int wt_left){
      if(wt_left==0) return 0;
      if(ind<0) return 0;
      if(dp[ind][wt_left]!=-1) return dp[ind][wt_left];

      int ans=Knapsack(ind-1,wt_left);
      if(wt_left-wt[ind]>=0)
      ans=max(ans,Knapsack(ind-1,wt_left-wt[ind])+val[ind]);
      return dp[ind][wt_left]=ans;
}  
signed main() {
    memset(dp,-1,sizeof(dp));
    int n,W;
    cin>>n>>W;
     for(int i=0;i<n;i++){
         cin>>wt[i]>>val[i];
     } 
    cout<<Knapsack(n-1,W);
}

