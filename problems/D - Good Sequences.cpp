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

typedef long long int ll;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 5
#define ACCURATE cout << fixed << setprecision(6)
#define MAX 1e9
#define MOD (int)(1e9 + 7 )
#define ExpMod (int)(1e9 + 6 )
#define vi vector<int>
//#define _DEBUG
using namespace std;

//#define _DEBUG
ll powmod(ll a, ll b) {
    a %= MOD;
    b %= MOD - 1;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;

        b >>= 1;
        a = (a * a) % MOD;
    }
    if (res < 0) cout << "A7a" << endl;
    return res % MOD;
}

int main() {

#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    map<int, int> primes;

    int sieve[100004];
    for (int i = 0; i < 100001; i++) {
        sieve[i] = 1;
    }
    sieve[0] = 0;
    sieve[1] = 0;
    for (int i = 2; i < 100001; i++) {
        if (sieve[i]) {
            for (ll j = (ll) i * i; j < 100001; j += i) sieve[j] = 0;
        }
    }
    for (int i = 0; i < 100001; i++) if (sieve[i] == 1) primes[i] = 0;
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int dp[n + 5];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        int val = a[i];
        if (primes.count(val)) {
            primes[val]++;
            dp[i] = max(primes[val], dp[i]);
            continue;
        }
        vector<int > divisors ;
        for (map<int, int>::iterator itr = primes.begin(); itr != primes.end(); itr++) {
            int p = itr->first;
            if (a[i] < (ll) p * p) break;
            if (a[i] % p == 0) {
                divisors.push_back(p) ;
                while(a[i] % p == 0 ) a[i] /= p ;
                itr->second++;
                dp[i] = max(dp[i], itr->second);
            }
        }
        if(a[i] != 1 ) {
            divisors.push_back(a[i]) ;
            primes[a[i]] ++ ;
            dp[i] = max(dp[i] , primes[a[i]]) ;
        }
        for(int p : divisors) {
            primes[p] = dp[i] ;
        }



        //  cout <<"When we end at " << i << " We get " << dp[i] << endl ;
    }

    int res = 0;
    for (int i = 0; i < n; i++) res = max(res, dp[i]);
    cout << res << endl;
    return 0;
}