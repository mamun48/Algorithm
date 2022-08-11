#include<bits/stdc++.h>
using namespace std;
 vector<int>coins;
 long long n, x;
 long long mem[1000010];
 #define inf 9999999;
 long long solve(long long x)
 {
    
     if(x < 0)
     {
         return inf;
     }
     if(x == 0)
     {
         return 0;
     }
    if(mem[x] != -1)
    {
        return mem[x];
    }
     
    long long ans = inf;
    for(int i = 0; i < n; i++)
    {
        ans = min(ans, 1 + solve(x-coins[i]));
    }
      mem[x] = ans;
      return mem[x];
 }
int main()
{
    int a;
    cin>>n>>x;
    
    for(int i = 0; i<= x; i++)
    {
        mem[i] = -1;
    }
    for(int i = 0; i<n; i++)
    {
        cin>>a;
        coins.push_back(a);
    }
  
    long long p = solve(x);
    if(p < 9999999)
    {
        cout<<p<<endl;
    }
    else cout<<-1<<endl;

    
}