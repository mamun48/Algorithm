#include<bits/stdc++.h>
using namespace std;

void Lps_array(string pat,int pat_len,int* lps);
void kmp(string txt,string pat)
{
    int txt_len = txt.size();
    int pat_len = pat.size();
    int lps[pat_len];
    Lps_array(pat,pat_len,lps);
    int i = 0;
    int j = 0;

    while(i<txt_len)
    {
        if(pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if(j == pat_len)
        {
            cout<<"Found pattern at index "<<i-j<<endl;
            j = lps[j-1];
        }
        else if(i<txt_len and pat[j] != txt[i])
        {
            if(j != 0)
            {
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }


}
void Lps_array(string pat, int pat_len, int* lps)
{
    int len = 0;
    lps[len] = 0;
    int i = 1;
    while(i<pat_len)
    {
        if(pat[len] == pat[i])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0)
            {
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}
int main()
{
    string txt,pat;
   // cin>>txt>>pat;
    // ofstream write("input.txt");
    // write<<txt<<pat;
    // write.close();
    ifstream read("text.txt");
    getline(read,txt);
    getline(read,pat);
    read.close();
    
    cout<<txt<<endl;
    cout<<pat<<" and size is "<<pat.size()<<endl;
    kmp(txt,pat);

}