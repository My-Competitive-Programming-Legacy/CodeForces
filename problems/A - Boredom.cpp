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
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

//#define _DEBUG
const int maxN = 1e5 + 3;
const int inf = 1e7;
const int Mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), f((int) 1e6, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }
    for (int i = 2; i <= 100000; i++) {
        f[i] *= i;
        f[i] = max(f[i - 1], f[i] + f[i - 2]);
    }
    cout << f[100000] << endl;


}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }

}