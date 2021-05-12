//Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
// #recusion
/*
Let weight elements = {1, 2, 3}
Let weight values = {10, 15, 40}
Capacity=6
output=65;
*/
/*
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
        return dp[n][w]= max(val[n-1]+knapsack(n-1,w-wt[n-1],wt,val),knapsack(n-1,w,wt,val));
    }
    else
    return dp[n][w]=knapsack(n-1,w,wt,val);
}
int main( )
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

*/
//#itretion
// A dynamic programming based
// solution for 0-1 Knapsack problem
#include <bits/stdc++.h>
using namespace std;
 
// A utility function that returns
// maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
 
// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];

}
int main( )
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
    cout<<knapSack(w,wt,val,n)<<endl;
    return 0;
}
