#include <bits/stdc++.h>

using namespace std;
#define endll '\n'
#define ar array
#define space ' '
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
const int mxN = 1e5, mxM = 1e5;
const int MOD = 1e9 + 7;


void solve() {
    int k, l;
    cin >> k >> l;
    for (int i = 1; i < 2000; i++) {
        for (int j = max(1,l - 1); j + i < 2000; j++) {
            ll sum = (i + j + k) / i;
            if (sum / j <= 1e6) {
                cout << i + j << endl;
                for (int c = 0; c < i - 1; c++) {
                    cout << 0 << space;
                }
                cout << -1 << space;
                ll part = sum / j;
                ll mod = sum % j;
                for (int c = 0; c < j - 1; c++) {
                    cout << part << space;
                }
                cout << part + mod << endl;
                return;
            }
        }
    }
    cout << -1 <<endl;

}

int main() {
    IO;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}