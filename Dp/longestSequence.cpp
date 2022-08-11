#include<bits/stdc++.h>
using namespace std;
int sequence[100];
int solve(int Arr[], int n)
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(Arr[j] <= Arr[i])
            {
              
                sequence[i] = sequence[j] + 1;
            }
        }
        if(ans < sequence[i])
        {
            ans = sequence[i];
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int Arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>Arr[i];
        sequence[i] = 1;
    }

    cout<<solve(Arr,n); 
    
}