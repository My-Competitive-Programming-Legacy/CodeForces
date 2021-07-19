#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endll "\n"
#define ar array
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 2e18;
const int mxN = 1e5, mxM = 6e2 + 1, MOD = 1e9 + 7;

int main() {
    IO;
    int n, c, x;
    cin >> n >> c >> x;
    string str(n, '?');
    for (int i = 0; i < x; i++) {
        int a;
        cin >> a;
        a--;
        str[a] = '0';
    }
    if (c % 2 == 1) {
        str[0] = '1';
        str[1] = '0';
        c--;
    }
    for (int i = 1; i < n - 1; i++) {
        if (c == 0)break;
        if (str[i] == '?' && str[i + 1] != '1' && str[i - 1] != '1') {
            str[i] = '1';
            str[i + 1] = '0';
            str[i - 1] = '0';
            c-=2;
        }
    }
    for (int i = 0; i < n; i++) {
        if (str[i] == '?')str[i] = '0';
    }
    cout << str << endl;
    return 0;

}