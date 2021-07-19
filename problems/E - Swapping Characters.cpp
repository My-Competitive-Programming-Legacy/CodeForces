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
    int k, n;
    cin >> k >> n;
    vector<string> a(k);
    vector<bool> has(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        set<char> chars;
        for (int j = 0; j < n; j++) {
            chars.insert(a[i][j]);
        }
        has[i] = (chars.size() != n);
    }
    int max_diff = 0;
    pair<int, int> indices;
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            int diff = 0;
            for (int l = 0; l < n; l++) {
                diff += (a[i][l] != a[j][l]);
            }
            if (diff > max_diff) {
                max_diff = diff;
                indices = {i, j};
            }
        }
    }
    if (max_diff > 4) {
        cout << -1 << endl;
        return;
    } else if (max_diff == 0) {
        swap(a[0][0], a[0][1]);
        cout << a[0] << endl;
        return;
    }
    vector<int> bad;
    for (int i = 0; i < n; i++) {
        if (a[indices.first][i] != a[indices.second][i]) {
            bad.push_back(i);
        }
    }
    int sz = (int) bad.size();
//    cerr << sz <<endl;
    int ind1 = indices.first;
    int ind2 = indices.second;
    for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
            for (int ind : {ind1}) {
                swap(a[ind][bad[i]], a[ind][bad[j]]);
                /*
                 * Check if it can make a difference
                 */
                bool can = true;
                for (int c = 0; c < k; c++) {
                    int diff = 0;
                    vector<char> tmp1;
                    vector<char> tmp2;
                    for (int ptr = 0; ptr < n; ptr++) {
                        if (a[ind][ptr] != a[c][ptr]) {
                            diff++;
                            if (diff < 3) {
                                tmp1.push_back(a[ind][ptr]);
                                tmp2.push_back(a[c][ptr]);
                            }
                        }
                    }
                    sort(tmp1.begin() , tmp1.end()) ;
                    sort(tmp2.begin() , tmp2.end()) ;
                    if (c == ind) continue;
                    if ((diff == 2 && tmp1 == tmp2) || (diff == 0 && has[c])) continue;
                    else {
                        can = false;
                        break;
                    }
                }
                if (can) {
                    cout << a[ind] << endl;
                    return;
                }
                swap(a[ind][bad[i]], a[ind][bad[j]]);
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
//    cin >> q;
    while (q--) {
        solve();
    }
}