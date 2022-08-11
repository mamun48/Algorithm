#include<bits/stdc++.h>
using namespace std;
void lps_array(string patt, int lps[])
{
    int len = 0;
    int i = 1;
    while(i<patt.size())
    {
        if(patt[len] == patt[i])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len == 0)
            {
                 i++;
            }
               
            else
            {
                len = lps[len - 1];
            }
        }
    }
}
void kmp(string str,string patt)
{
    int n = str.size();
    int m = patt.size();
    int lps[m] = {0};
    lps_array(patt,lps);

    int i = 0, j = 0;
    while(i<n)
    {
        if(str[i] == patt[j])
        {
            i++;
            j++;
        }
        if(m == j)
        {
            cout<<"String matched from index "<<i-m<<" to "<<i-1<<endl;
            j = lps[j-1];
        }
        else if(i<n and str[i] != patt[j])
        {
            if(j == 0)
            {
                i++;
            }
            else
            {
                j = lps[j-1];
            }
        }
    }

}
int main()
{
    string str, patt;
    cin>>str>>patt;
    kmp(str,patt);
}