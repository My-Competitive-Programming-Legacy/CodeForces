#include <bits/stdc++.h>

using namespace std;
int dp[100 * 2000 + 3];

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a[i] = t;
        for (int j = 100*2000; j > 0 ; j-- ) {
            if (j - t >= 0) {
                dp[j] = (dp[j] | dp[j - t]);
            }
        }
        sum += t;
    }
   
    if ((sum % 2 == 1) || (dp[sum / 2] == 0)) {
        cout << 0 << endl;
        return 0;
    }
    while (true) {
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 1) {
                cout << 1 << endl << i + 1 << endl;
                return 0;
            }
        }
        for (int i = 0; i < n; ++i) a[i] >>= 1;
    }
    return 0;
}