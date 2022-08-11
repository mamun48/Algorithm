#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum;
    cin>>n>>sum;
    int elements[n];
    int arr[n][sum+1];
    for(int i=0;i<n;i++){
        cin>>elements[i];
        arr[i][0]=0;
    }
    sort(elements,elements+n);
    for(int i = 0;i<n; i++){
        for(int j=0;j<= sum; j++){
            if(j < elements[i]){
                if(i == 0){
                    arr[i][j]=0;
                }
                else{
                    arr[i][j]=arr[i-1][j];
                
                }
            
            }
            else if(j==elements[i]){
                arr[i][j]=1;
            }
            else{
                if(i==0){
                    arr[i][j]=0;
                }
                else{
                    if(arr[i-1][j] != 0){
                        arr[i][j]=arr[i-1][j];
                    }
                    else{
                        if(arr[i-1][j-elements[i]] == 0){
                            arr[i][j] = 0;
                        }
                        else{
                            arr[i][j] = arr[i-1][j-elements[i]] + 1;
                        }
                    }
                }
            }
                
        }
    }
     if(arr[n-1][sum]){
       cout<<"YES"<<endl;
       int i = n-1;
       int j = sum;
       int count = 0;
       while(1){
           if(count == arr[n-1][sum])
           break;
           if(arr[i-1][j] != arr[i][j]){
               cout<<elements[i]<<" ";
                count++;
               j = j - elements[i];
           }
           else{
               i = i-1;
           }
       }
   }
   else{
       cout<<"NO";
   }
   
}