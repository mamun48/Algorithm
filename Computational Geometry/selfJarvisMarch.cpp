#include<bits/stdc++.h>
using namespace std;
struct Point
{
    int x,y;
};
int oriantation(Point p, Point q, Point r)
{
    int val = (r.x - q.x) * (q.y - p.y) -
              (r.y - q.y) * (q.x - p.x);
    if(val == 0) return 0;
    return(val>0)? 1 : 2;
}
void convexHull(Point points[], int n)
{
    if(n<3)
    return ;
    int l = 0;
    for(int i = 1; i<n; i++)
    {
        if(points[l].x > points[i].x)
            l = i;
    } 
    int p = l, q;
    vector<Point>Hull;
    do
    {
        Hull.push_back(points[p]);
        q = (p + 1) % n;
        for(int i = 0; i < n; i++)
        {
            if(oriantation(points[p],points[i],points[q]) == 2)
            {
                q = i;
            }
        }
        p = q;
        
    } while (p != l);

    for(int i = 0; i < Hull.size(); i++)
    {
        cout<<Hull[i].x<<" "<<Hull[i].y<<endl;
    }
    

}
int main()
{
    int n, a, b;
    cin >> n;
    Point points[n];
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;
        points[i].x = a;
        points[i].y = b; 
    }
    convexHull(points,n);
}
