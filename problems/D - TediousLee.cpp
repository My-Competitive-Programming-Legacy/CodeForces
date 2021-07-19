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
const ll INF = LONG_LONG_MAX;
const int maxN = 2000 * 1000 + 3;
const int Mod = 1000000000 + 7;
int dp[maxN], dp2[maxN], ans[maxN];

void solve() {
    int n;
    cin >> n;
//    for(int i=1;i<=n;i++) cerr << dp[i] << space ;
//    cerr << endl;
//    for(int i=1;i<=n;i++) cerr << dp2[i] << space ;
//    cerr << endl;
//    for(int i=1;i<=n;i++) cerr << ans[i] << space ;
//    cerr << endl;
    cout << ans[n] << endl;

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
    cin >> q;
    dp[1] = 1;
    dp2[1] = 0;
    ans[1] = 0 ;
    for (int i = 2; i <= maxN; i++) {
        dp[i] = (dp2[i - 1] *1LL* 2 + dp[i - 1])%Mod;
        dp2[i] = dp[i - 1];
        ans[i] = (4 *1LL* dp2[i - 1])%Mod;
        if (i > 3) ans[i] += ans[i - 3];
        ans[i] %= Mod ;
    }
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}