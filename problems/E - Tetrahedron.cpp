#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
using namespace std;


/**Global stuff */

/**Global stuff */
#define N 4

void multiply(ll mat1[][5],
              ll mat2[][5],
              ll res[][5]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            res[i][j] = 0;
            for (k = 0; k < N; k++) {
                res[i][j] += (mat1[i][k] *mat2[k][j]) % MOD;
                res[i][j] %= MOD;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    ll a[5][5];
    ll b[5][5];
    ll c[5][5];
    ll d[5][5];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            a[i][j] = (i != j);
            b[i][j] = (i != j);
            c[i][j] = (i != j);
            d[i][j] = (i != j);
        }

    n--;
    while (n > 0) {
        if (n & 1) {
            multiply(a, c, d);
            for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) c[i][j] = d[i][j];
        }
        multiply(a, a, b);
        for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) a[i][j] = b[i][j];
        n >>= 1;
    }
    cout << d[3][3] << endl;

}