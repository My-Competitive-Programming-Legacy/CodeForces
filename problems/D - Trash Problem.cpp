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
#define mp make_pair
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
#define ar array
const int maxN = 2e5 + 4;
set<int> st;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    multiset<int> segs;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        segs.insert(a[i] - a[i - 1]);
    }
    int seg = (segs.empty()) ? 0 : *segs.rbegin();
    cout << a[n - 1] - a[0] - seg << endl;
    while (q--) {
        int t, v;
        cin >> t >> v;
        if (t == 0) {
            // delete
            auto itrU = st.upper_bound(v);
            auto itrL = st.lower_bound(v);
            if (itrL != st.begin() && (itrU != st.end())) {
                itrL--;
                int before = *itrL;
                int after = *itrU;
                segs.erase(segs.find(v - before));
                segs.erase(segs.find(after - v));
                segs.insert(after - before);
            } else if (itrL == st.begin()) {
                int after = *itrU;
                if (!segs.empty())
                    segs.erase(segs.find(after - v));
            } else {
                int before = *(--itrL);
                if (!segs.empty())
                    segs.erase(segs.find(v - before));
            }
            st.erase(st.find(v));
        } else if (t == 1) {
            auto itrU = st.upper_bound(v);
            auto itrL = st.lower_bound(v);
            if (itrL != st.begin() && (itrU != st.end())) {
                itrL--;
                int before = *itrL;
                int after = *itrU;
                segs.erase(segs.find(after - before));
                segs.insert(after - v);
                segs.insert(v - before);
            } else if (itrL == st.begin()) { // add at the first
                int after = *itrL;
                if (!segs.empty())
                    segs.insert(after - v);
            } else {
                int before = *st.rbegin();
                if (!segs.empty())
                    segs.insert(v - before);
            }
            st.insert(v);
            if (st.size() == 2) {
                segs.insert((*st.rbegin() - *st.begin())) ;
            }

        }
        int lb = 0, rb = 0;
        if (!st.empty()) {
            lb = *st.begin();
            rb = *st.rbegin();
        }
        if (segs.empty())
            cout << 0 << endl;
        else {
            seg = *segs.rbegin();
            cout << rb - lb - seg << endl;
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
    cout.tie(0); // FAST IO5
    int q = 1;
    //  cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}