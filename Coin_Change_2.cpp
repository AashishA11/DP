// https://leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[301][10001];
int func(int ind,int amount,vector<int>& coins) {
    if(amount==0) return 1;
    if(ind<0) return 0;
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    int ways=0;
    for(int coin_amount=0;coin_amount<=amount;coin_amount+=coins[ind]){
       if(amount-coin_amount>=0)
       ways+=func(ind-1,amount-coin_amount,coins);
    }
    return dp[ind][amount]=ways;
} 
int coinChange(vector<int>& coins, int amount) {
    memset(dp,-1,sizeof(dp));
    int ans=func(coins.size()-1,amount,coins);
    return ans;
}

signed main() {
    
    vector<int>coins={1,2,5};
    cout<<coinChange(coins,11);

    }

