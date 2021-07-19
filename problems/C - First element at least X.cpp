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
    seg[v] = max(seg[2 * v], seg[2 * v + 1]);
}

void build(int tl = 0, int tr = n - 1, int v = 1) {
    if (tl == tr) seg[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build(tl, tm, 2 * v);
        build(tm + 1, tr, 2 * v + 1);
        combine(v);
    }
}

void update(int idx, int val, int tl = 0, int tr = n - 1, int v = 1) {
    if (tl == tr) {
        seg[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (idx <= tm) {
        update(idx, val, tl, tm, 2 * v);
    } else if(idx <= tr ) {
        update(idx, val, tm + 1, tr, 2 * v + 1);
    }else {
        cout << "A*A" <<endl;
    }
    combine(v);
}

int lower_bound(int val, int tl = 0, int tr = n - 1, int v = 1) {

    if (seg[v] < val) {
        return -1;
    }
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) / 2;
    if (seg[2 * v] >= val) {
        return lower_bound(val, tl, tm, 2 * v);
    } else {
        return lower_bound(val, tm + 1, tr, 2 * v + 1);
    }
}

int main() {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    build();
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            int v;
            cin >> v;
            update(x, v);
        } else {
            cout << lower_bound(x) << endl;
        }
    }
}