#include <bits/stdc++.h>

    using namespace std;
    typedef long long int ll;
    #define space " "
    #define debug(val) "[ " << #val " : " << (val) << " ]" << space
    #define vi vector<int>
    #define vl vector<ll>
    #define vll vector<vector<ll>>
    #define vii vector<vector<int>>
    #define PI (double)(atan(1)*4)
    #define pb push_back
    #define ff first
    #define ss second
    #define pi pair<int , int >
    #define INF LONG_LONG_MAX
    #define FINF 1000000000000
    #define EPS (double)0.0000000001
    vi dx = {-1, 0, 0, 1};
    vi dy = {0, -1, 1, 0};
    const int Mod = (int) ((int) 1e9 + 7);
    //#define _DEBUG
    #define ar array
    void solve() {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> mp;
        ll pre = 0;
        long double ans = 0;
        for (int i = 0; i < n; i++) {
            ans += a[i] * 1LL * (i) - pre;
            vector<ll> vals = {a[i] + 1, a[i] - 1, a[i]};
            vector<ll> cnts = {mp[a[i] + 1], mp[a[i] - 1], mp[a[i]]};
    //        for(auto v : vals ) cerr << v << space ;
    //        cerr << endl;
    //        for(auto v : cnts ) cerr <<v << space ;
    //        cerr <<endl;
    //        cerr << "================" <<endl;
            for (int j = 0; j < 3; j++) {
                ans -= (a[i] -vals[j]) * cnts[j];
            }
            pre += a[i];
            mp[a[i]]++;
        }
        printf("%.0Lf",ans);
    }

    int main() {
        int q =1 ;
    //    cin >> q;
        while (q--) {
            solve();
        }
    }