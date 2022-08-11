#include<bits/stdc++.h>
using namespace std;
int mem[100];
int fibo(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(mem[n] != -1)
    {
        return mem[n];
    }
    mem[n] = fibo(n-1) + fibo(n-2);
    return mem[n];

}
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i<= n; i++)
    {
        mem[i] = -1;
    }
   cout<< fibo(n)<<endl;
}