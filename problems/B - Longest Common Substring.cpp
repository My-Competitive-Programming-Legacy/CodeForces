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
    string t;
    int sz1, sz2;
    cin >> s;
    sz1 = (int) s.size();
    s += '$';
    cin >> t;
    sz2 = (int) t.size();
    s += t;
    s += '#';

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
//    for (int i = 0; i < n; i++) {
//        cout << c[i] << endl;
//    }
    vector<int> lcp(n);
    k = 0;
    for (int i = 0; i < n - 1; i++) {
        int pos = c[i];
        int pre = p[pos - 1];
        while (s[i + k] == s[pre + k]) k++;
        lcp[pos] = k;
        k = max(k - 1, 0);
    }
    int ans = 0;
    int st = -1;
    auto type = [&](int index) {
        return index < sz1;
    };
//    for (int i = 0; i < n; i++) {
//        cout << lcp[i] << space << p[i] << space << s.substr(p[i]) << type(p[i]) << space << type(p[i-1]) << endl;
//    }
    for (int i = 1; i < n; i++) {

        bool different = type(p[i]) != type(p[i - 1]);
        if (different && lcp[i] > ans ) {
            st = p[i] ;
            ans = lcp[i];
        }
    }
    if (ans == 0) {
        cout << '\n';
    } else {
        cout << s.substr(st, ans) << '\n';
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