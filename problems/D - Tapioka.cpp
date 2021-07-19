#include <bits/stdc++.h>

using namespace std;
#define endll '\n'
#define ar array
#define space ' '
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
const int mxN = 1e5, mxM = 1e5;
const int MOD = 1e9 + 7;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

struct grid {
    vector<vector<int>> vec;

    grid() {
        vec.resize(6, vector<int>(6));
    }

    void read() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                cin >> vec[i][j];
            }
        }
    }

    bool same(grid s) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                if (vec[i][j] != s.vec[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

};

void solve() {
    string t1 = "bubble";
    string t2 = "tapioka";
    bool ok = false;
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        if (s == t1 || s == t2) {

        } else {
            ok = true;
            cout << s << space;
        }
    }
    if (!ok) {
        cout << "nothing";
    }
    cout << endl;

}

int main() {
    IO;
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}