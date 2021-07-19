#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include <set>
#include <map>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    int lo = 0, hi = 1000000000;
    pair<int, int> ans;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        //cerr << "here we have " << mid << endl ;
        vector<pair<int, int >> bits;
        set<int> st;
        for (int i = 0; i < n; i++) {
            int val = 0;
            for (int j = 0; j < m; j++) {
                if (a[i][j] >= mid) val |= (1 << j);
            }
            if (!st.count(val)) {bits.push_back({val, i});st.insert(val);}
        }
        int size = (int) bits.size();
        bool ok = false;
        pair<int, int> indices;
        if(mid == 9 ) {
            int x = 0;
        }
        for (int i = 0; i < size; i++) {
            for (int j = i ; j < size; j++) {
                if ((bits[i].first | bits[j].first) == ((1 << m) - 1)) {
                  //  cerr << "our mid is " << space << mid << " and we found both " << i << space << j << endl;
                    ok = true;
                    indices = {bits[i].second, bits[j].second};
                }
            }
        }
        if (ok) {
            ans = {indices.first, indices.second};
            lo = mid + 1;
        } else
            hi = mid - 1;
    }
    cout << ans.first + 1  << space << ans.second + 1 << endl;

}

//cout << "Case #" << i << ": ";
int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}