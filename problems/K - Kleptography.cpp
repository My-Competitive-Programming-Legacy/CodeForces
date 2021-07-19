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
    int n, m;
    cin >> n >> m;
    // a + k = b ;
    string s;
    vector<char> a(m);
    cin >> s;
    string b;
    cin >> b;
    for (int i = m - 1; i >= 0; i--) {
        if (s.empty()) {
            break;
        }
        a[i] = s.back();
        s.pop_back();
    }
    for (int i = m - 1; i >= n; i--) {
        char k = (char) ('a' + (b[i] - a[i] + 2 * 26) % 26);
        a[i - n] = k;
    }
    for (char c : a) {
        cout << c;
    }
    cout << endl;


}