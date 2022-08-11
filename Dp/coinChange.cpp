#include<bits/stdc++.h>
using namespace std;
vector<int>coins;
int n;
int mem[100][100];
int coinChange(int i, int w)
{
    if(w<0)
    {
        return 99999;
    }
    if( i == n)
    {
        if(w == 0)
        {
            return 0;
        }
        return 99999;
    }
    if(mem[i][w] != -1)
    {
        return mem[i][w];
    }
    int ans = 0;
    int var1 = 1 + coinChange(i+1, w-coins[i]);
    int var2 = coinChange(i+1, w);
    ans = min(var1,var2);
    mem[i][w] = ans;
    return mem[i][w];
}
int main()
{
    int w,a; 
    cin>>n>>w;
    for(int i = 0; i<n; i++)
    {   
        cin>>a;
        coins.push_back(a);
    }
    for(int i = 0; i<100; i++)
    {
        for(int j = 0; j<100; j++)
        {
            mem[i][j] = -1;
        }
    }
    cout<<coinChange(0,w);
}