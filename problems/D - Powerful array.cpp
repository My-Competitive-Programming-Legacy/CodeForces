#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "
const int maxN = 200000;
const int BLK = (int) sqrt(maxN);

struct Query {
    int l, r, idx;

    bool operator<(const Query &o) {
        int b1l = l / BLK;
        int b2l = o.l / BLK;
        if (b1l != b2l) return b1l < b2l;
        else return r < o.r;
    }
};

int f[1000000 + 3];
ll res[maxN + 3];
ll ans = 0;
int L = 0, R = -1;
vector<int> a;

void remove(int i) {
    ll cur = a[i];
    ll k = f[cur];
    ans = ans - 2 * k * cur + cur;
    f[cur]--;
}

void add(int i) {
    ll cur = a[i];
    ll k = f[cur];
    ans = ans + 2 * k * cur + cur;
    f[cur]++;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<Query> queries;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        queries.push_back({l, r, i});
    }
    sort(queries.begin(), queries.end());
    for (auto query : queries) {
        int l = query.l;
        int r = query.r;
        int idx = query.idx;
        while (L < l) {
            remove(L++);
        }
        while (L > l) {
            L--;
            add(L);
        }
        while (R > r) {
            remove(R);
            R--;
        }
        while (R < r) {
            R++;
            add(R);
        }
        res[idx] = ans;
    }
    for(int i=0;i<q;i++){
        cout << res[i] << space ;
    }
    cout << endl;


}