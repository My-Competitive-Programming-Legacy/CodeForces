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
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        mp[t].push_back(i + 1);
    }
    int pivot = -1;
    int smallest = n + 1;
    for (auto v : mp) {
        if (v.second.size() < smallest) {
            smallest = v.second.size();
            pivot = v.first;
        }
    }
    if (n - smallest >= smallest - 1) {
        cout << "YES" << endl;
        for (auto v : mp[pivot]) {
            st.erase(v);
        }
        vector<int> &a = mp[pivot];
        for (int i = 0; i + 1 < (int) a.size(); i++) {
            cout << a[i] << space << *st.begin() << endl;
            cout << a[i + 1] << space << *st.begin() << endl;
            st.erase(st.begin());
        }
        for (auto v : st) {
            cout << v << space << a[0] << endl;
            //st.erase(st.begin()) ;
        }
    } else {
        cout << "NO" << endl;
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