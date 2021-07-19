#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
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
#define debug(val) "[ " << #val " : " << (val) << " ]\n"
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define pi pair<int , int >

void solve() {
    string s, t;
    cin >> s >> t;
    string txt;
    cin >> txt;
    map<char, char> mp;
    int n = (int) s.size();
    for (int i = 0; i < n; i++) {
        mp[s[i]] = t[i];
        mp[s[i] - 32] = t[i] - 32;
    }
    for (char  c : txt) {
        if (c >= '0' && c <= '9') cout << c;
        else
            cout << mp[c];
    }


}

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