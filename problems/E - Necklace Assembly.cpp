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

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int f[30];
    for (int i = 0; i < 26; i++)f[i] = 0;
    for (auto c : s) {
        f[c - 'a']++;
    }
    sort(f, f + 26, greater<>());
    for (int can = n; can >= 1; can--) {
        int vis[can + 2];
        vi g[can + 1];
        for (int i = 0; i <= can; i++) vis[i] = 0;
        // construct the graph :)
        for (int i = 0; i < can; i++) {
            g[i].push_back((i+k)%can);
            g[i].push_back(((i-k)%can + can)%can);
        }
        // dfs to count the number of needed characters and count of each one
        vi connected;
        for (int i = 0; i < can; i++) {
            int nocn = 1; // number of connected nodes
            if (!vis[i]) {
                vis[i] = 1;
                stack<int> st;
                st.push(i);
                while (!st.empty()) {
                    int cur = st.top();
                    st.pop();
                    for (auto adj : g[cur]) {
                        if (vis[adj] != 1) {

                            nocn++;
                            st.push(adj);
                            vis[adj] = 1;
                        }
                    }

                }
                connected.push_back(nocn);
            }
        }
        sort(connected.begin(), connected.end(), greater<>());
        bool ok = 1;
        multiset<int> chars;
        for(int i=0;i<26;i++) chars.insert(f[i]) ;
        for (int i = 0; (i < (int) connected.size()) && ok; i++) {
            int ff = *chars.rbegin();
            if (ff < connected[i]) ok = false;
            else if(ff > 0 ){
                auto itr = chars.find(ff) ;
                chars.erase(itr);
                ff-=connected[i] ;
                chars.insert(ff) ;
            }

        }
        if (ok) {
            cout << can << endl;
            return;
        }
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
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}