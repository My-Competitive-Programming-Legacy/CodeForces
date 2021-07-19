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
int par[(int) MAX + 5];
int dep[(int) MAX + 5];
vi g[(int) MAX + 5];
int in[MAX + 5] ;
int out[MAX + 5] ;
vi q((int)2e5 + 5) ; // vector<int>
int euler = 0 ;
void pre_dfs(int depth = 0, int parent = 1, int cur = 1) {
    par[cur] = parent;
    dep[cur] = depth;
    in[cur] = euler ++ ;
    for (int i = 0; i < g[cur].size(); i++) {
        int child = g[cur][i];
        if(child != parent) pre_dfs(depth + 1 , cur , child) ;
    }
    out[cur]= euler++ ;

}
int main() {
    IO ;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    pre_dfs() ;
    for(int i = 0 ; i< m ; i++ ){
        int k ;
        cin >> k ;
        int maxDepth = -1 ;
        int deeper = -1 ;
        for(int ii=0; ii < k ; ii++ ) {
            cin >> q[ii] ;
            if(dep[q[ii]] > maxDepth) {
                deeper = q[ii] ;
                maxDepth = dep[q[ii]] ;
            }
        }
        bool ok = true ;
        int indeep = in[deeper] ;
        int outdeep = out[deeper] ;
        for(int j = 0 ; ok && j < k ; j++ ){
            int curindeep = in[q[j]] ;
            int curoutdeep = out[q[j]] ;
            int parentindeep = in[par[q[j]]]  ;
            int parentoutdeep = out[par[q[j]]]  ;
            bool flag1 = curindeep <= indeep && curoutdeep >= outdeep ;
            bool flag2 = parentindeep <= indeep && parentoutdeep >= outdeep ;
            ok = flag1 || flag2 ;


        }
        if(ok) cout << "YES" ; else cout << "NO" ;
        cout << endl;
    }
    return 0;
}
