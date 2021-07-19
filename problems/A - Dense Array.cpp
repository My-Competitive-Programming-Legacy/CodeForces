#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define vii vector<vector<int>>
#define ld long


const int mxN = 103;
int query = 1;

void solve() {
    int n ;
    cin >> n ;
    vector<ll> a(n) ;
    for(int i=0;i<n;i++){
        cin >> a[i] ;
    }
    ll ans = 0 ;
    for(int i=1;i<n;i++){
        ll mx = max(a[i] , a[i-1] ) ;
        ll mn = min(a[i] , a[i-1]) ;
        while(2 * mn < mx ) {
            mn = 2 * mn ;
            ans ++ ;
        }
    }
    cout << ans << endl;
   
}

int main() {
//    freopen("in" , "r" , stdin);
//    freopen("out.txt" , "w" , stdout);
    IO;
    int q = 1;
    if (query) cin >> q;
    for (int i = 1; i <= q; i++) {
//        cout << "Case #" << i << ": ";
        solve();
    }
}