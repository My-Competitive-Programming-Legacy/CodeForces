#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define endll "\n"
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 301;
const int N = 2005;
const int MOD = 1e9 + 7;

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> a(n + 1, 1);
    int q;
    cin >> q;
    int ans = 0;
    int off = 0;
    while (q--) {
        int val;
        cin >> val;
        for (int i = val; i <= n; i += val) {
            if (a[i] == 1) {
                off++;
            } else {
                off--;
            }
            a[i] = 1 ^ a[i];
        }
        ans = max(ans, off);
    }
    cout<<ans<<endl;
    return 0;
}