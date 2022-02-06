// https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int N=1e5+10;
int n;
 int a[N][4];
 int dp[N][4];
int func(int day,int flag){

    if(day==n) return 0;
    if(dp[day][flag]!=-1) return dp[day][flag];
    int ans=0;
     
     if(flag==0){
        ans=max(ans,func(day+1,1)+a[day][1]);
        ans=max(ans,func(day+1,2)+a[day][2]);
        ans=max(ans,func(day+1,3)+a[day][3]);
    }else if(flag==1){
        ans=max(ans,func(day+1,2)+a[day][2]);
        ans=max(ans,func(day+1,3)+a[day][3]);
    }else if(flag==2){
        ans=max(ans,func(day+1,1)+a[day][1]);
        ans=max(ans,func(day+1,3)+a[day][3]);
    }else{
        ans=max(ans,func(day+1,2)+a[day][2]);
        ans=max(ans,func(day+1,1)+a[day][1]);
    }
   return dp[day][flag]=ans;
} 
signed main() {
     cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=1;j<4;j++){
            cin>>a[i][j];
        }
    }

  cout<<func(0,0)<<endl;
}

