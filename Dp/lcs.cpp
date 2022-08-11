#include<bits/stdc++.h>
using namespace std;
int mem[100][100];
int lcs(int i, int j, string s, string w)
{
    if(i == s.size() or j == w.size())
    {
        return 0;
    }
    if(mem[i][j] != -1)
    {
        return mem[i][j];
    }
    int ans = 0;
    if(s[i] == w[j])
    {
        ans = 1 + lcs(i+1,j+1,s,w);
    }
    else
    {
        int val1 = lcs(i,j+1,s,w);
        int val2 = lcs(i+1,j,s,w);
        ans = max(val1,val2);
    }
    mem[i][j] = ans;
    return mem[i][j];
}
int main()
{
    string s,w;
     cin>>s>>w;
     for(int i = 0; i<100; i++)
     {
         for(int j = 0; j<100; j++)
         {
             mem[i][j] = -1;
         }
     }
   cout<<lcs(0,0,s,w)<<endl;
}