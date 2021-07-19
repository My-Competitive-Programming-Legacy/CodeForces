#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endll "\n"
#define ar array
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const ll INF = 301;
const int N = 2005;
const int MOD = 1e9 + 7;
const int maxN = 4e5 + 3;
#define space " "

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int up = 1, down = 1;
    for (int i = n - 1; i >= 0; i--) {
        ll ballon = i + 1;
        if (ballon < a[i]) {
            cout << "-1" << endl;
            return 0;
        } else {
            ll aa = a[i], bb = ballon;
            if (up *1ll* bb > aa *1ll* down) {
                up = aa;
                down = bb;
            }
        }
    }
    cout << fixed << setprecision(10) << up/(double)down << endl;


}