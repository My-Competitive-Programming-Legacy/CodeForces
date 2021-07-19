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

#define pi pair<int , int >
#define INF LONG_LONG_MAX
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
    string s;
    cin >> s;
    int n = (int) s.size();
    vector<char> a;
    for (int i = 0; i < n / 2; i++) {
        if (n % 2 && s[i] == s[n / 2]) {
            swap(s[n - i - 1], s[n / 2]);
        } else if (n % 2 && s[n - i - 1] == s[n / 2]) {
            swap(s[i], s[n / 2]);
        } else {
            if (s[i] != s[n - 1 - i]) {
                a.push_back(s[i]);
                a.push_back(s[n - i - 1]);

            }
        }
    }
    if (a.size() > 4 || a.size() == 2) {
        cout << "NO" << endl;
    } else {
        if (a.size() == 4) {
            sort(a.begin(), a.end());
            if (a[0] == a[1] && a[2] == a[3]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "YES" << endl;
        }
    }
}

#define _DEBUG

int main() {
#ifdef _DEBUG
    //  freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    // cin >> q;
    for (int i = 1; i <= q; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
}