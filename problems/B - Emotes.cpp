#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  unsigned long long ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int N=1e6+10;
int main(){
    IO;
    int n , k , m ;
    cin >> n >> k >> m ;
    vector<ll> a(n) ;
    for(int i=0;i<n;i++) cin >> a[i] ;
    sort(a.begin() , a.end() , greater<>()) ;
    int f = k/(m+1);
    int rem = k%(m+1) ;
    ll res = f * (a[0] * (m) + a[1]) + rem * a[0] ;
    cout<<res<<endl;
}