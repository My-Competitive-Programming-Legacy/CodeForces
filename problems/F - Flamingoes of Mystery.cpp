#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endll "\n"
#define ar array
#define speed() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll INF = 1e18 + 18;
const int mxN = 2e5 + 5, MOD = 1e9 + 7;

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int t;
    cin >> t;
    return t;
}

int main() {
    int n;
    cin >> n;
    vector<int> ans;
    int last = query(1 , n );
    int sum = last ;
    for (int i = 2; i < n; i++) {
        int cur = query(i, n);
        ans.push_back(last - cur);
        last = cur;
    }
    int rev = query(1 , n-1 ) ;
    ans.push_back(last - (sum - rev)) ;
    ans.push_back(sum - rev) ;
    cout << "!" << " " ;
    for(auto v : ans ) cout << v << " " ;
    cout << endl;

}