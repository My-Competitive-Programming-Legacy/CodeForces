#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define pb push_back
#define space " "
#define ar array
#define pi pair<int,int>
#define ff first
#define ss second
const vector<int> dx = {0, 1, 0, -1, 0, 1, 1, -1, -1};
const vector<int> dy = {0, 0, 1, 0, -1, 1, -1, 1, -1};

void solve() {
    ll n ;
    cin>>n ;
    ll l = 1 , r = 1e9 ;
    ll ans= -1 ;
    while(l<=r){
        ll mid= l +(r-l)/2;
        ll done =  (mid-1)*mid/ 2 ;
        if(done <n){
            ans = mid ;
            l =mid +1 ;
        }else{
            r=mid - 1 ;
        }
    }
    cout<<n-(ans*(ans-1)/2)<<endl;
}

int main() {
//    freopen("input.txt" , "r" , stdin) ;
//    freopen("output.txt" , "w" , stdout) ;
    int q = 1;
    // cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}