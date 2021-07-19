#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <stack>

typedef long long int ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 5
#define ACCURATE cout << fixed << setprecision(6)
#define MAX (int)2e5
#define MOD (int)(998244353  )
#define ExpMod (int)(1e9 + 6 )
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define MAT_SIZE 5

//#define _DEBUG
using namespace std;

//#define _DEBUG
//====================================================================================================

int inverse(ll, ll);

//====================================================================================================
//====================================================================================================
//====================================================================================================
int powmod(ll a, ll b, ll mod) {
    //if (b < 0) return inverse(powmod(a, -1 * b));
    a %= mod;
    // b %= (mod - 1);
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * 1ll * a) % MOD;
        }
        a = (a * 1ll * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}

int inverse(ll a, ll primemod) {
    return powmod(a, 500000002, primemod);
}

int nxt() {
    int x;
    cin >> x;
    return x;
}

int lcm(int a, int b) {
    return a * 1ll / __gcd(a, b) * b;
}

//====================================================================================================

//====================================================================================================
//====================================================================================================
//==================

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        unordered_set<int> st;
        unordered_set<int> st2;
        unordered_set<int> res;
        unordered_set<int> ans;
        ll sum = 0;
        for (int i = 0; i < n -1 ; i++) {
            if (st.count(a[i])) break;
            st.insert(a[i]);
            sum += a[i];
            if (sum == (i + 1) * 1ll * (i + 2) / 2) res.insert(i + 1);
        }
        reverse(a.begin(), a.end());
        sum = 0;
        for (int i = 0; i < n -1 ; i++) {
            if (st2.count(a[i])) break;
            st2.insert(a[i]);
            sum += a[i];
            if (sum == (i + 1) * 1ll * (i + 2) / 2) {
                // n - (i+1)
                if (res.count(n - (i + 1))) ans.insert(n - (i + 1));
            }
        }
        if (ans.empty()) cout << 0 << endl;
        else {
            cout << ans.size() << endl;
            for (unordered_set<int>::iterator it = ans.begin(); it != ans.end(); it++) {
                cout << *it << space << n - *it << endl;
            }
        }
    }

    return 0;
}