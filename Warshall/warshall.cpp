#include<bits/stdc++.h>
using namespace std;
int graph[100][100];
void warshall(int node)
{
    for(int k = 1; k<= node; k++)
    {
        for(int i = 1; i<= node; i++)
        {
            for(int j = 1; j<= node; j++)
            {
                if(graph[i][k] + graph[k][j]< graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}
int main()
{
    int node, edge, a, b, w;
    cin>>node>>edge;
    for(int i = 0; i<= node; i++)
    {
        for(int j = 0; j<= node; j++)
        {
            graph[i][j] = 9999;
        }
    }

    for(int i = 0; i<edge; i++)
    {
        cin>>a>>b>>w;
        graph[a][b] = w;
    }
    warshall(node);
    cout<<graph[5][3];


}