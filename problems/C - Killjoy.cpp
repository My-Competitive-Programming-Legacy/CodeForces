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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    bool ok = true;
    bool help = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ok &= (a[i] == x);
        if (a[i] == x) help = true;
    }
    ll change = 0;
    for (int i = 0; i < n - 1; i++) {
        change += (x - a[i]);
    }
    a[n - 1] += -1 * change;
    if (ok) {
        cout << 0 << endl;
    } else if (a[n - 1] == x || (help)) {
        cout << 1 << endl;
    } else {
        cout << 2 << endl;
    }


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