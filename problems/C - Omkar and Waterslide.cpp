#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
#define mp make_pair
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++ ) cin >> a[i] ;
    int st = 0;
    vector<pi > bad;
    for (int i = 0; i < n; i++) {
        if(st == -1 ) st = i ;
        if (i < n -1 && a[i] <= a[i + 1]) {
            continue;
        } else {
            bad.pb({a[st], a[i]});
            st = -1;
        }
    }
    //if(st != -1 ) bad.pb({a[st] , a.back()}) ;
   // for(auto p : bad ) {cerr << p.ff << space << p.ss << endl; }
    ll ans = 0 ;
    reverse(bad.begin() , bad.end()) ;
    for(int i=0;i<(int)bad.size() -1  ; i++) {
        ans += (bad[i+1].ss - bad[i].ff  ) ;
    }
    cout << ans << endl;
}

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}