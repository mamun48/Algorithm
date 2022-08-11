#include <bits/stdc++.h>
using namespace std;
int vis[1010][1010] = {0};
vector<string>str;
int rooms = 0;
int m,n;
int dfs(int i, int j)
{
    vis[i][j] = 1;
    
    if (str[i][j + 1] != '#' and i>-1 and i<n and j>-1 and j<m and vis[i][j + 1] == 0)
    {
        return 1 + dfs(i, j + 1);
    }
    if(str[i][j-1] != '#' and i>-1 and i<n and j>-1 and j<m and vis[i][j-1]==0)
    {
       
       return 1 + dfs(i, j - 1);
    }
    if(str[i+1][j] != '#' and i>-1 and i<n and j>-1 and j<m and vis[i+1][j]==0)
    {
        
        return 1 + dfs(i+1, j);
    }
    if(str[i-1][j] != '#' and i>-1 and i<n and j>-1 and j<m and vis[i-1][j]==0)
    {
       
        return 1 + dfs(i-1, j);
    }
    else return 0;
   

       
}


int Count(int n, int m)
{
   
    int temp = 0, var;
    for (int i = 0; i < n; i++)
    {   var = 0;
        for (int j = 0; j < m; j++)
        {
         
            if (str[i][j] != '#' and vis[i][j] == 0)
            {
               
               
               var = 1 + dfs(i,j);
                 
            }
        }
      if(var > temp)
        temp = var;
    }
    return temp;
   
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
   // cout<<str[1][1];
   //cout<<str[2][2]<<endl;
   
   Count(n,m);
}