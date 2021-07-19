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
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int sz = to_string(n).size();
        cout << 10 * (to_string(n)[0] - '0' -1 ) + (sz * (sz + 1)) / 2 << endl;
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
    //   cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}