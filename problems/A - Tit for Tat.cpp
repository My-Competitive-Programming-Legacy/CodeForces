#include <bits/stdc++.h>
/*
Created on 4/22/2021 by Hamza Hassan:
*/
using namespace std;
typedef long long int ll;
#define space " "
#define debug(val) "[ " << #val " : " << (val) << " ]" << space
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)

#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        while (a[i] > 0 && (k > 0)) {
            a[i] -= 1;
            k -= 1;
            a[n-1]+=1;
        }
    }
    for (auto v : a) cout << v << space;
    cout << endl;
}

int main() {
    bool debug = false;

    if (debug) {
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}