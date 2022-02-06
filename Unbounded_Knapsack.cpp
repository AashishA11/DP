#include<bits/stdc++.h>
using namespace std;
int dp[1002][1002];
int knapsack(int n,int w,int wt[],int val[])
{
    memset(dp,-1,sizeof(dp));
    if(n==0||w==0)
    return 0;
    if(dp[n][w]!=-1)
    return dp[n][w];
    if(w>=wt[n-1])
    {
        return dp[n][w]= max(val[n-1]+knapsack(n,w-wt[n-1],wt,val),knapsack(n-1,w,wt,val));
    }
    else
    return dp[n][w]=knapsack(n-1,w,wt,val);
}
int main()
{ 
    int n;
    cin>>n;
    int wt[n];
    int val[n];
    for(int i=0;i<n;i++)
    cin>>wt[i];
    for(int i=0;i<n;i++)
    cin>>val[i];
    int w;
    cin>>w;
    cout<<knapsack(n,w,wt,val)<<endl;
    return 0;
}