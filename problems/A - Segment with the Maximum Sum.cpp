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
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

struct Node {
    ll sum;
    ll pref;
    ll suff;
    ll max_subsegment;

//    Node(ll sum, ll pref, ll suff, ll ms) {
//        this->sum = sum;
//        this->pref = pref;
//        this->suff = suff;
//        max_subsegment = ms;
//    }

};

const int maxN = 100000 + 3;
vector<Node> seg(4 * maxN);
vector<int> a(maxN);
int n;

void debug_the_segment_tree(int tl = 0, int tr = n - 1, int v = 1) {

    cerr << "From L = " << tl << " And R = " << tr << space;
    cerr << debug(seg[v].sum) << debug(seg[v].pref) << debug(seg[v].suff) << debug(seg[v].max_subsegment) << endl;
    if (tl == tr)
        return;
    int tm = (tl + tr) / 2;
    debug_the_segment_tree(tl, tm, 2 * v);
    debug_the_segment_tree(tm + 1, tr, 2 * v + 1);
}

void reform_leaf(int v) {
    if (seg[v].sum < 0) {
        seg[v].pref = max(seg[v].pref,0LL);
        seg[v].suff = max(seg[v].suff,0LL);
        seg[v].max_subsegment = max(seg[v].max_subsegment,0LL);

    }
}

void combine(int v) {
    ll big_seg_sum = seg[2 * v].sum + seg[2 * v + 1].sum;
    ll big_seg_pre = max(seg[2 * v].pref, seg[2 * v].sum + seg[2 * v + 1].pref);
    ll big_seg_suff = max(seg[2 * v + 1].suff, seg[2 * v + 1].sum + seg[2 * v].suff);

    Node current = {big_seg_sum, big_seg_pre, big_seg_suff, 0};
    current.max_subsegment = max(seg[2 * v].suff + seg[2 * v + 1].pref,
                                 max(seg[2 * v].max_subsegment, seg[2 * v + 1].max_subsegment));
    seg[v] = current;
    reform_leaf(v) ;
}

void build(int tl = 0, int tr = n - 1, int v = 1) {
    if (tl == tr) {
        Node current = {a[tl], a[tl], a[tl], a[tl]};
        seg[v] = current;
        reform_leaf(v);
        return;
    }
    int tm = (tl + tr) / 2;
    build(tl, tm, 2 * v);
    build(tm + 1, tr, 2 * v + 1);
    combine(v);
}

void update(int idx, int val, int tl = 0, int tr = n - 1, int v = 1) {
    if (tl == tr) {
        Node current = {val, val, val, val};
        seg[v] = current;
        reform_leaf(v);
    } else {
        int tm = (tl + tr) / 2;
        if (idx <= tm)
            update(idx, val, tl, tm,2*v);
        else
            update(idx, val, tm + 1, tr,2*v+1);
        combine(v);
    }
}

ll get_max_subsegment() {
    return seg[1].max_subsegment;
}

void solve() {
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    build();
    cout << get_max_subsegment() << endl;
    while (m--) {
//        debug_the_segment_tree();
//        cerr << "End" <<endl;
        int index, new_val;
        cin >> index >> new_val;
        update(index, new_val);
        cout << get_max_subsegment() << endl;
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
        solve();
    }
}