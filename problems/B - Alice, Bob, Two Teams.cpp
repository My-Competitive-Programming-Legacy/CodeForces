#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int main() {
    IO;
    ll n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    string str;
    cin >> str;
    ll ans = 0;
    ll ans_here = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'B') {
            ans += vec[i];
        }
    }
    ll temp = ans;
    ans_here = ans;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'A') {
            ans_here += vec[i];
        } else {
            ans_here -= vec[i];
        }
        ans = max(ans, ans_here);
    }
    ans_here = temp;
    for (int i = n - 1; i >= 0; i--) {
        if (str[i] == 'A') {
            ans_here += vec[i];
        } else {
            ans_here -= vec[i];
        }
        ans = max(ans, ans_here);
    }
    cout << ans << endl;
    return 0;
}