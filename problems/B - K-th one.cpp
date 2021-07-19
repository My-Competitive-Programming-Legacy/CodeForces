#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "
const int maxN = 100000 + 1;
int seg[maxN * 4];
int n;
int a[maxN];

void combine(int v) {
    seg[v] = seg[2 * v] + seg[2 * v + 1];
}

void build(int tl = 0, int tr = n - 1, int v = 1) {
    if (tl == tr) {
        seg[v] = a[tr];
    } else {
        int tm = (tl + tr) >> 1;
        build(tl, tm, 2 * v);
        build(tm + 1, tr, 2 * v + 1);
        combine(v);
    }
}

void update(int idx, int tl = 0, int tr = n - 1, int v = 1) {
    if (tl == tr) {
        seg[v] = 1 ^ seg[v];
        return;
    }
    int tm = (tl + tr) / 2;
    if (idx <= tm) {
        update(idx, tl, tm, 2 * v);
    } else {
        update(idx, tm + 1, tr, 2 * v + 1);
    }
    combine(v);
}

int kth_one(int k, int tl = 0, int tr = n - 1, int v = 1) {
    if (tl == tr) return tl;
    int left = seg[2 * v];
    if (left > k) {
        return kth_one(k, tl, (tl + tr) / 2, 2 * v);
    } else {
        return kth_one(k - left, 1 + (tl + tr) / 2, tr, 2 * v + 1);
    }
}

int main() {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    build();
    while (q--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            update(v);
        } else {
            cout << kth_one(v) << endl;
        }
    }
}