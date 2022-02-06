// https://atcoder.jp/contests/dp/tasks/dp_e
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int wt[105];
int val[105]; 
int dp[105][N];
int Knapsack(int ind,int value_left){
    if(value_left==0) return 0;
    if(ind<0) return 1e15;
    if(dp[ind][value_left]!=-1) return dp[ind][value_left];
     // Dont choose
    int ans=Knapsack(ind-1,value_left);

       //choose
    if((value_left-val[ind])>=0)
    ans=min(ans, Knapsack(ind-1,value_left-val[ind])+wt[ind]);

      return dp[ind][value_left]=ans;
}  
signed main() {
    memset(dp,-1,sizeof(dp));
    int n,W;
    cin>>n>>W;
     for(int i=0;i<n;i++){
         cin>>wt[i]>>val[i];
     } 
     int max_value=1e5;
    for(int i=max_value;i>=0;i--){
          if(Knapsack(n-1,i)<=W){
              cout<<i<<endl;
              break;
          }
    }
    
}

