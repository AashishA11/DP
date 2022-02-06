// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[205][20005];
int func(int ind,int sum_left,vector<int>&nums){
      
      if(sum_left==0) return true;
      if(ind<0) return false;
      if(dp[ind][sum_left]!=-1) return dp[ind][sum_left];

     bool isPossible= func(ind-1,sum_left,nums);
      if(sum_left-nums[ind]>=0)
      isPossible |= func(ind-1,sum_left-nums[ind],nums);
      return dp[ind][sum_left]= isPossible;
}
 bool canPartition(vector<int>& nums) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];

        }
        if(sum%2==1){
            return false;
        }
        sum=sum/2;
        return func(nums.size()-1,sum,nums);

}

signed main() {
    int t;
    cin>>t;
    while(t--){
        
    }

}

