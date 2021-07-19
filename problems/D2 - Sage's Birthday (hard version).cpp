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
const int Mod = (int) ((int) 1e9 + 7);

//#define _DEBUG
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = -1;
    int lb = 2, rb = (n - 1) / 2;
    while (lb <= rb) {
        int mb = (lb + rb) / 2;
        bool ok = true;
        map<int, int> mp;
        for (int i = mb; i < n; i++) {
            mp[a[i]]++;
        }
        for (int i = 0; i < mb; i++) {
            int x1 = a[i];
            int x2 = a[i + 1];
            auto itr = mp.upper_bound(max(x1, x2));
            if (itr == mp.end()) {
                ok = false;
                break;
            } else {
                itr->ss--;
                if (itr->ss == 0) {
                    mp.erase(itr);
                }
            }
        }
        auto itr = mp.upper_bound(a[0]);
        if (itr != mp.end()) {
            itr->ss--;
        } else {
            ok = false;
        }
        if (ok) {
            ans = mb;
            lb = mb + 1;
        } else {
            rb = mb - 1;
        }
    }
    if (ans == -1 && n > 2 && (a[n - 2] > a[0])) {
        cout << 1 << endl;
        cout << a[n - 1] << " " << a[0] << " " << a[n - 2] << " ";
        for (int i = 1; i < n - 2; i++) {
            cout << a[i] << " ";
        }
    } else if (ans != -1) {
        cout << ans << endl;
        map<int, int> mp;
        for (int i = ans; i < n; i++) {
            mp[a[i]]++;
        }
        vector<int> res;
        for (int i = 0; i < ans; i++) {
            res.push_back(a[i]);
            auto itr = mp.upper_bound(max(a[i], a[i + 1]));
            res.push_back(itr->first); // can't be map end
            itr->second--;
            if (itr->second == 0) {
                mp.erase(itr);
            }
        }
        auto itr = mp.upper_bound(a[0]);
        cout << itr->first << " ";
        itr->second--;
        if (itr->second == 0) {
            mp.erase(itr);
        }
        for (auto v : res) cout << v << " ";
        for (auto v : mp) {
            for (int i = 0; i < (v.second); i++) {
                cout << v.first << " ";
            }
            cout << endl;
        }

    } else {
        cout << 0 << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;

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
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }

}