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
#define ff first
#define ss second
#define pi pair<int , int >
#define INF LONG_LONG_MAX
#define EPS (double)0.0000000001
#define mp make_pair
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int Mod = (int) ((int) 1e9 + 7);
//#define _DEBUG

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a;
    vector<int> odd, even;
    for (auto c : s) {
        a.push_back((c - '0') % 2);
    }
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0) {
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }
    sort(odd.begin(), odd.end(), greater<int>()); // raze
    sort(even.begin(), even.end());
    int sz = n;
    int turn = 0;
    while (n > 1) {
        if (!turn)odd.pop_back();
        else even.pop_back();
        n -= 1;
        turn = !turn;
    }
    int last;
    if (!odd.empty()) last = odd.back();
    else last = even.back();
    if (last % 2 == 0) {
        cout << 2 << " ";
    } else {
        cout << 1 << " ";
    }
    cout << endl;
}

int main() {
#ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); // FAST IO
    int q = 1;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}