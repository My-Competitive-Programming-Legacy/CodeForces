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

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
const double eps = 0.0000001;
const int maxN = 1000 + 3;
int a[maxN][maxN];
int vis[maxN][maxN];
int n, m;
const int notVisited = 2001;

bool valid(int i, int j) {
    return (i >= 0) && (i < n) && (j >= 0) && (j < m);
}

const vi dx = {-1, 0, 0, 1};
const vi dy = {0, 1, -1, 0};

// ii ,jj should be valid index to expand
vector<pair<int, int >> p;

void bfs() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 4; k++) {
                int ii = i + dx[k];
                int jj = j + dy[k];
                if (valid(ii, jj) && a[ii][jj] == a[i][j] && vis[i][j] == notVisited) {
                    vis[i][j] = 0;
                    p.push_back({i, j});
                    break;
                }
            }
        }
    }
    for (int i = 0; i < (int) p.size(); i++) {
        pair<int, int> cur = p[i];
        for(int k =0 ; k< 4 ; k++ ){
          int ii = cur.first + dx[k] ;
          int jj = cur.second + dy[k] ;
          if(valid(ii , jj ) && vis[ii][jj] == notVisited) {
              vis[ii][jj] = vis[cur.first][cur.second] + 1 ;
              p.push_back({ii , jj });
          }
        }
    }

}




void solve() {
    int q;
    string s;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
            vis[i][j] = notVisited;
        }
    }
    bfs();

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++)
//            cerr << vis[i][j] << space;
//        cerr << endl;
//    }
    while (q--) {
        int i, j;
        ll p;
        cin >> i >> j >> p;
        i--, j--, p--;
        if (vis[i][j] == notVisited) cout << a[i][j] << endl;
        else {
            if (vis[i][j] > p) cout << a[i][j] << endl;
            else cout << ((p - (ll) vis[i][j] + 1LL) % 2 + a[i][j]) % 2 << endl;
        }
    }

}


int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
    int q = 1;
    // cin >> q ;
    for (int i = 1; i <= q; i++) {
        solve();
        //cout << "Case #" << i << ": ";
    }
}