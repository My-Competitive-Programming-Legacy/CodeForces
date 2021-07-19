#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define PI (double)(atan(1)*4)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int , int >
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int maxN = 100001;

struct Segment {
    vector<int> seg;
    vector<int> a; // zero based :)
    Segment(vi &a) {
        int sz = (int) a.size();
        seg.resize(4 * sz);
        this->a = a;
    }

    void build(int tl, int tr, int v) {
        if (tl == tr) seg[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(tl, tm, 2 * v);
            build(tm + 1, tr, 2 * v + 1);
            seg[v] = min(seg[2 * v], seg[2 * v + 1]);
        }
    }

    int get_minimum(int tl, int tr, int v, int l, int r) {
        if (l > r) return INT_MAX;
        int tm = (tl + tr) / 2;
        if (tl == l && tr == r) return seg[v];
        int left = get_minimum(tl, tm, 2 * v, l, min(tm, r));
        int right = get_minimum(tm + 1, tr, 2 * v + 1 , max(tm + 1, l), r);
        return min(left, right);
    }

    void update(int tl, int tr, int v, int idx, int val) {
        if (tl == tr) {
            seg[v] = val;
            return;
        }
        int tm = (tl + tr) / 2;
        if (idx >= tl && idx <= tm) update(tl, tm, 2 * v, idx, val);
        else update(tm + 1, tr, 2 * v + 1, idx, val);
        seg[v] = min(seg[2 * v], seg[2 * v + 1]);
    }


};

void solve() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Segment s(a);
    s.build(0, n - 1, 1);
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 2) {
            r-- ;
            cout << s.get_minimum(0, n-1, 1, l, r) << endl;
        } else {
            s.update(0, n - 1, 1, l, r);
        }
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
    //    cin >> q;
    for (int i = 1; i <= q; i++) {
        solve();
    }
}