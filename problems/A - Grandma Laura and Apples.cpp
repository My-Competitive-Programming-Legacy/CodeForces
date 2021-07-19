#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main(){
    IO;
    ll n ,  p ;
    cin>>n>>p;
    vector<string>vec(n);
    for(int i = 0;  i< n ; i ++){
        cin>>vec[i];
    }
    ll num = 0 ;
    for(int i = n-1 ; i>=0 ; i--){
        if(vec[i]=="halfplus"){
            num*=2 ;
            num++;
        }else{
            num*=2;
        }
    }
    ll ans = 0;
    while (num){
        if(num%2==0){
            ans+=num/2*p;
        }else{
            ans+=num/2*p;
            ans+=p/2;
        }
        num/=2;
    }
    cout<<ans<<endl;
    return 0;
}