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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    ll maximum = LONG_LONG_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maximum = max(maximum, a[i]);
    }
    vl first, second;
    ll maximum2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        ll nxt = maximum - a[i];
        maximum2 = max(maximum2, nxt);
        first.pb(nxt);
    }
    for (int i = 0; i < n; i++) {
        ll nxt = maximum2 - first[i];
        second.pb(nxt);
    }
    k = k % 2;
    if (k == 0) {
        for (auto v : second) cout << v << space;
    } else {
        for (auto v : first) cout << v << space;
    }
    cout << endl;
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