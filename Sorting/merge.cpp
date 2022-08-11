#include<bits/stdc++.h>
using namespace std;
int Arr[100];
int temp[100];
void mergeSort(int low, int high)
{
    if(low == high) return;
    int mid;
    mid = (low + high)/2;
    mergeSort(low, mid);
    mergeSort(mid+1,high);
    int i,j,k;
    for(i = low, j = mid+1, k = low; k <= high; k++)
    {
        if(i == mid+1) 
        {
            temp[k] = Arr[j++];
        }
        else if(j == high + 1)
        {
            temp[k] = Arr[i++];
        }
        else if (Arr[i] < Arr[j])
        {
            temp[k] = Arr[i++];
        }
        else
        {
            temp[k] = Arr[j++];
        }
    }
    for(k = low; k<= high; k++)
    {
        Arr[k] = temp[k];
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>Arr[i];
    }
    mergeSort(0,n-1);
    

   for(int i = 0; i < n; i++)
    {
        cout<<Arr[i]<<endl;
    }
}