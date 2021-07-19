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
    string s;
    cin >> s;
    int n = s.size();
    int f[27];
    int l = 0, r = 25;
    bool thereisAns = 0;
    for (;!thereisAns &&  r<n ; r++ , l++) {
        stack<int> lost;
        for (int i = 0; i < 26; i++) f[i] = 0;
        bool ok = true;
        for (int i = l; ok && i <= r; i++) {
            if (s[i] == '?') {
                lost.push(i);
                continue;
            }
            f[s[i] - 'A']++;
            if (f[s[i] - 'A'] > 1) {
                ok = false;
            }
        }
        if (!ok) continue;
        thereisAns = 1;
       for(int j = 0 ; j < 26 ; j++ ) {
           if(f[j] == 0 ) {
               int next = lost.top() ;
               lost.pop() ;
               s[next] = 'A' + j ;
           }
       }
        break;
    }
    if (!thereisAns || n < 26) cout << -1 << endl;
    else {
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') cout << 'A'; else cout << s[i];
        }
    }


    return 0;
}
