#include<bits/stdc++.h>
using namespace std;
#define inf 99999 
vector<pair<int,int>>graph[100];
int cost[100];
priority_queue<pair<int,int>>pq;
pair<int,int> top;

void dijkastra(int node)
{
    int visit[node] = {0};
     pq.push({0,1});
     int  positive;
     while(!pq.empty())
     {
         top = pq.top();
         pq.pop();
         
         positive = abs(top.first);
         if(visit[top.second] != 1)
         {
             visit[top.second] = 1;
             for(int i = 0; i<graph[top.second].size();i++)
             {
                
                 if(visit[graph[top.second][i].second] != 1)
                 {
                     if(cost[graph[top.second][i].second] > graph[top.second][i].first + positive)
                     {
                         cost[graph[top.second][i].second] = graph[top.second][i].first + positive;
                         pq.push({-(cost[graph[top.second][i].second]),graph[top.second][i].second});
                         
                     }
                     else
                     {
                          pq.push({-(cost[graph[top.second][i].second]),graph[top.second][i].second});
                     }
                     
                 }
             }
         }
     }
  
}

int main()
{
    int node,edge,a,w,b;
    cin>>node>>edge;
    cost[1] = 0 ;
    for(int i = 2; i<= node+1; i++)
    {
        cost[i] = inf; 
    }

    for(int i = 1; i<= edge; i++)
    {
        cin>>a>>b>>w;
        graph[a].push_back({w,b});
    }
    dijkastra(node);
     cout<<cost[node]<<endl;
}