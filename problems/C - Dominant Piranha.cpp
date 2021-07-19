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
#define INF (int)3e5
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG

template<typename T>
// remove all occurrences of item in the container v
inline void remove(vector<T> &v, const T &item) {
    v.erase(std::remove(v.begin(), v.end(), item), v.end());
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;
    int best = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
        best = max(a[i], best);
    }
    if (st.size() == 1) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (a[i] == best) {
                if ((i + 1 < n && a[i + 1] < a[i]) || (i - 1 >= 0 && a[i] > a[i - 1])) {
                    cout << i + 1 << endl;
                    return;
                }
            }
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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}