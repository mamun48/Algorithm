#include<bits/stdc++.h>
using namespace std;
int cost[100],weight[100],w,n;
int mem[100][100];

int napsack(int i, int w)
{
    if(i == n)
    {
        return 0;
    }
   
    int ans = 0 , var1 = 0, var2 = 0;
    if(w - weight[i] >= 0)
    var1 = cost[i] + napsack(i+1, w - weight[i]);
    var2 = napsack(i+1, w);
    ans = max(var1,var2);
    return ans;
}
int main()
{
    
    cin>>n>>w;
    for(int i = 0; i< n; i++)
    {
        cin>>weight[i]>>cost[i];
    }
    cout<<napsack(0,w);
}