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
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG
#define ar array

struct hash_pair {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++) {
        vector<int> c1(n + 1, 0);
        for (int j = 0; j < i; j++) {
            c1[a[j]]++;
        }
        ll res = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] == a[i]) {
                ans += res;
            }
            res += c1[a[j]];

        }
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