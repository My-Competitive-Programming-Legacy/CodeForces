#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
#define MOD (int)(1e9  + 7)

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
    return {a.first + b.first, a.second + b.second};
}

const int maxN = 1003;
int dp1[maxN][maxN];
int dp2[maxN][maxN];
int a[maxN][maxN];
int b[maxN][maxN];

pair<int, int> trailing(ll x) {
    int twos = 0, fives = 0;
    while (x > 0 && x % 2 == 0) {
        twos++;
        x /= 2;
    }
    while (x > 0 && x % 5 == 0) {
        fives++;
        x /= 5;
    }
    return make_pair(twos, fives);
}

int n;

int getMinSum(int a[maxN][maxN], int dp[maxN][maxN]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j == 0) dp[i][j] = a[i][j];
            else if (i == 0) dp[i][j] = a[i][j] + dp[i][j - 1];
            else if (j == 0) dp[i][j] = a[i][j] + dp[i - 1][j];
            else dp[i][j] = a[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n - 1][n - 1];
}

void debug() {
    cerr << "The two array" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cerr << a[i][j] << space;
        cerr << endl;
    }
    cerr << "The five array" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cerr << b[i][j] << space;
        cerr << endl;
    }

}


string res = "";

void print(int a[maxN][maxN], int dp[maxN][maxN]) {
    int i = n - 1, j = n - 1;
    while (i + j != 0) {
        dp[i][j] -= a[i][j];
        if (i > 0 && dp[i][j] == dp[i - 1][j]) {
            res += 'D';
            i--;
        } else {
            res += 'R';
            j--;
        }
    }
}

void solve() {
    cin >> n;
    pair<int, int> zidx;
    bool zero = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            cin >> t;
            pair<int, int> ex = trailing(t);
            if (t == 0) {
                a[i][j] = 1;
                b[i][j] = 1;
                zero = true;
                zidx = {i, j};
            } else {
                a[i][j] = ex.first;
                b[i][j] = ex.second;
            }
        }
    }
    int two = getMinSum(a, dp1);
    int five = getMinSum(b, dp2);
    if (zero && (min(two, five) > 1)) {
        cout << 1 << endl;
        res = "";
        for (int i = 0; i < zidx.second; i++) res += 'R';
        for (int i = 0; i < zidx.first; i++) res += 'D';
        for (int i = zidx.second + 1; i < n; i++) res += 'R';
        for (int i = zidx.first + 1; i < n; i++) res += 'D';
        cout << res << endl;
    } else {
        if (two < five) {
            cout << two << endl;
            print(a, dp1);
        } else {
            cout << five << endl;
            print(b, dp2);
        }
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
}

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    IO;
//    int q;
//    cin >> q;
//    for (int i = 1; i <= q; i++) {
//        cout << "Case #" << i << ": ";
//        solve();
//    }
    solve();

    return 0;
}