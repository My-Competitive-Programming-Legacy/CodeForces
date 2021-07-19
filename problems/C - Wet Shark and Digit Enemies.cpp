#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endll "\n"
#define ar array
#define speed() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int INF = 1e9;
const int mxN = 2e5, mxM = 1e2, MOD = 1e9 + 7;

int n;

void solve() {

    cin >> n;
    if (n == 1) {
        cout << 1 << endll;
        cout << 9 << endll;
        cout << 0 << endll;
        cout << -72 << endll;
    } else if (n == 2){
        cout << 50 << endll;
        cout << 19 << endll;
        cout << 25 << endll;
        cout << -63 << endll;
    } else {
        for (int i = 0; i < n-2; ++i) {
            cout << 9;
        }
        cout << 50 << endll; cout << 1;
        for (int i = 0; i < n-2; ++i) {
            cout << 0;
        }
        cout << 9 << endll;
        int res = 81*(n-2)+25+49;
        vector<int> v (n,9); int index = n-1;
        while (res) {
            int temp = res%10; v[index]-=temp; index--;
            res /= 10;
        }
        for (int i = 0; i < n; ++i) {
            cout << v[i];
        }
        cout << endll;
        n--;
        for (int i = 0; i < n-2; ++i) {
            cout << 9;
        }
        cout << 27 << endll;
    }


}

int main() {
    speed()
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}