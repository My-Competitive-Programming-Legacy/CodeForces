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
#define FINF 1000000000000
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG
#define ar array

void radix_sort(vector<pair<pair<int, int>, int >> &a) {
    int n = (int) a.size();
    // count sort first
    // store in buckets
    // solve
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        cnt[a[i].first.second]++;
    }
    vector<int> pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    vector<pair<pair<int, int>, int >> new_a(n);
    for (int i = 0; i < n; ++i) {
        int element = a[i].first.second;
        new_a[pos[element]] = a[i];
        pos[element]++;
    }
    cnt.clear();
    pos.clear();
    cnt.resize(n);
    pos.resize(n);
    a = new_a; // by reference
    for (int i = 0; i < n; i++) {
        cnt[a[i].first.first]++;
    }
    pos[0] = 0;
    for (int i = 1; i < n; i++) {
        pos[i] = pos[i - 1] + cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        int element = a[i].first.first;
        new_a[pos[element]] = a[i];
        pos[element]++;
    }
    a = new_a;
}

void solve() {
    string s;
    cin >> s;
    s += '$';

    int n = (int) s.size();
    vector<int> p(n), c(n);
    vector<pair<char, int>> aa(n);
    for (int i = 0; i < n; i++) {
        aa[i] = {s[i], i};
    }
    sort(aa.begin(), aa.end());
    for (int i = 0; i < n; i++) {
        p[i] = aa[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
        if (aa[i].first == aa[i - 1].first) {
            c[p[i]] = c[p[i - 1]];
        } else {
            c[p[i]] = c[p[i - 1]] + 1;
        }
    }
    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int >> a(n);
        // build the
        for (int i = 0; i < n; i++) {
            a[i] = {{c[i], c[(i + (1LL << k)) % n]}, i};
        }
        radix_sort(a);
        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k += 1;
    }
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;

        bool ok = false;
        auto can = [&](int mb) {
            int st = p[mb];
            for (int i = 0; i < (int) t.size(); i++) {
                if (s[st] == t[i]) {
                    if (i == (int) t.size() - 1)
                        return 0;
                    st = (st + 1) % n;

                } else if (s[st] > t[i]) {
                    return -1; // mb is bigger
                } else {
                    return 1;
                }
            }
        };
//        for (int i = 0; i < n; i++) {
//            cout << s.substr(p[i]) << space;
//        }
//        cout << endl;
        int ans1 = 1, ans2 = 0;
        int lb = 1, rb = n - 1;
        while (lb <= rb) {
            int mb = (lb + rb) / 2;
            int cann = can(mb);
            if (cann == 0) {
                ans1 = mb;
                rb = mb - 1;
            } else if (cann == 1) { // t is bigger
                lb = mb + 1;
            } else {
                rb = mb - 1;

            }
        }

        lb = 1, rb = n - 1;
        while (lb <= rb) {
            int mb = (lb + rb) / 2;
            int cann = can(mb);
            if (cann == 0) {
                ans2 = mb;
                lb = mb + 1;
            } else if (cann == 1) { // t is bigger
                lb = mb + 1;
            } else {
                rb = mb - 1;

            }
        }
        cout << ans2 - ans1 + 1 << endl;
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
//    cin >> q;
    while (q--) {
        solve();
    }
}