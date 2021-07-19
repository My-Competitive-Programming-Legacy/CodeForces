#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define EPS 0.000000001
#define space " "
const int maxN = 100000 + 2;
int n;
int seg[maxN * 4];

void update(int idx, int tl = 1, int tr = n, int v = 1) {
    if (tl == tr) {
        seg[v] = 1;
        return;
    }
    int tm = (tl + tr) / 2;
    if (idx <= tm) {
        update(idx, tl, tm, 2 * v);
    } else
        update(idx, tm + 1, tr, 2 * v + 1);

    seg[v] = seg[2 * v] + seg[2 * v + 1];
}

int sum(int L, int R, int tl = 1, int tr = n, int v = 1) {
    if (R < L) return 0;
    else if (tl == L && tr == R) return seg[v];
    int tm = (tl + tr) / 2;
    return sum(L, min(R, tm), tl, tm, 2 * v) + sum(max(tm+1, L), R, tm + 1, tr, 2 * v + 1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cout << sum(t, n) << " ";
        update(t);
    }
}