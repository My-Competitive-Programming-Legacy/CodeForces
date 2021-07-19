#include <bits/stdc++.h>

#define ll long long int
using namespace std;
#define space " "
#define vii vector<vector<int>>
#define vi vector<int>
#define EPS 0.000000001
#define ld long  double

void solve() {
    string s;
    cin >> s;
    vector<ll> n(3), p(3), need(3);
    ll r;
    for (int i = 0; i < 3; i++)cin >> n[i];
    for (int i = 0; i < 3; i++)cin >> p[i];
    cin >> r;

    map<char, int> mp;
    for (auto c : s) mp[c]++;
    need[0] = mp['B'];
    need[1] = mp['S'];
    need[2] = mp['C'];

    ll lb = 0, rb = 1e12 + max({n[0] , n[1] , n[2]});
    ll ans = 0;
    while (lb <= rb) {
        ll mb = (lb + rb) / 2;
        vector<ll> possible(3);
        for (int i = 0; i < 3; i++) {
            possible[i] = max(0LL , (mb * need[i] - n[i]));
        }
        ll possible_price = 0;
        for (int i = 0; i < 3; i++) {
            possible_price += possible[i] * p[i];
        }
        if (possible_price <= r) {
            ans = mb;
            lb = mb + 1;
        } else {
            rb = mb - 1;
        }
    }
    cout << ans <<endl;
}

int main() {
    int T = 1;
//    cin >> T;
    for (int i = 1; i <= T; i++) {
//        cout << "Case #" << i << ": ";
        solve();
    }

}