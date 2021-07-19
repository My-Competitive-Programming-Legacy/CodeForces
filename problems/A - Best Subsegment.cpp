#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  unsigned long long ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int N=1e6+10;
int main(){
    IO;
   int n ;
   cin>>n ;
   int arr[n+2];
   int m=0;
   for(int i =0 ;i<n;i++){
       cin>>arr[i];
       m=max(m, arr[i]);
   }
    int ans=0;
    int ansHere=0;
    for(int i = 0 ; i<n ;i++){
       if(arr[i]==m){
           ansHere++;
       }else{
           ansHere=0;
       }
       ans=max(ans,ansHere);
   }
    cout<<ans<<endl;
}
// 7 10 9 8 8 