#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
#include <set>
#include <time.h>
#include <deque>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
#define vll vector<vector<ll>>

void solve() {
    ll n, m;
    cin >> n >> m;
    if (n < m) {
        cout << 1 << endl;
        return;
    } else if (m == n) {
        cout << 2 << endl;
        return;
    }
    vector<vector<ll>> mat(m, vector<ll>(m, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0) {
                mat[i][j] = (j == 0) || (j == m - 1);
            } else if (j == i - 1) {
                mat[i][j] = 1;
            }
        }
    }
    const int Mod = 1000000007;
    auto mul_mat = [&](vll m1, vll m2) {
        vll res(m, vector<ll>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = 0;
                for (int k = 0; k < m; k++) {
                    res[i][j] += (m1[i][k] * m2[k][j]);
                    res[i][j] %= Mod;
                }
            }
        }
        return res;
    };

//    for(int i=0;i<m;i++){
//        for(int j=0;j<m;j++){
//            cerr << mat[i][j] << space ;
//        }
//        cerr <<  endl;
//    }
    vector<vector<ll>> res(m, vector<ll>(m, 0));
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) res[i][j] = (i == j);
    ll b = n - m;
    while (b > 0) {
        if ((b & 1) == 1) {
            res = mul_mat(res, mat);
            // res = res * a ;
        }
        mat = mul_mat(mat, mat);
        // a = a * a ;
        b >>= 1;
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += res[0][i] * (1 + (i == 0));
        ans %= Mod;
    }
    cout<< ans << endl;

}

//#define _DEBUG

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    //cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}