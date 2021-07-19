#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 2e9+10
#define MOD (int)1e9
using namespace std;
using namespace std;
vector<int> all;
int operation = 0;

void solve(int n, string res = "") {
    if (n == 0) return all.push_back(stoi(res));
    operation++;
    solve(n - 1, res + '0');
    solve(n - 1, res + '1');
}

int dp[(int) 1e6 + 9];

int main() {
    solve(7);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) dp[i] = MAX;
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < all.size() && all[j] <= i; j++) {
            dp[i] = min(dp[i - all[j]] + 1, dp[i]);
        }
    }
    cout << dp[n] << endl;

    vector<int> ans;
    while (n>0) {
        for (auto i : all) {
            if (i <= n && 1 + dp[n - i] == dp[n]) {
                ans.push_back(i);
                n = n- i ;
                break ;
            }
        }

    }
    for(auto i : ans) cout << i << space ;


    return 0;
}