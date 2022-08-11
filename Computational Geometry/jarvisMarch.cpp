#include<bits/stdc++.h>
using namespace std;
struct Point
{
    int x,y;
};

int oriantation(Point p, Point q, Point r)
{
    int val = (r.x - q.x)*(q.y - p.y) -
              (r.y - q.y)*(q.x - p.x);
    if(val == 0) return 0;
    if(val>0) return 1;
    else return 2;
}
void convexHull(Point points[],int n)
{
    if(n<3)
    {
        cout<<"This is a line this will not be convex hull "<<endl;
        return;
    }
    vector<Point>Hull;
    int l = 0;
    for(int i = 1; i < n; i++)
    {
        if(points[i].x < points[l].x)
        {
            l = i;
        }
    }
    int p = l, q;
    do 
    {
        Hull.push_back(points[p]);
        q = (p + 1) % n;
        for(int i = 0; i < n; i++)
        {
           if(oriantation(points[p], points[i], points[q]) == 2)
           {
               q = i;
           } 
        }
        p = q;
    }while (p != l);

    //print the hull
    for(int i = 0; i < Hull.size(); i++)
    {
        cout<<Hull[i].x<<" "<<Hull[i].y<<endl;
    }
    
    
}

int main()
{
    int n, a, b;
    cin>>n;
    Point points[n];
    for(int i = 0; i<n; i++)
    {
        cin>>a>>b;
        points[i].x = a;
        points[i].y = b;
    }
    convexHull(points,n);
    
}
