#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define space " "
#define endll '\n'
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
#define FINF 1000000000000
#define EPS (double)0.0000000001
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};
const int N = 315; //316;
const int maxN = 1e5;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << 2 <<endll;
        cout << 1 << space << 2 << endll;
    } else {
        cout << 2 <<endll;
        int nxt = n - 1;
        cout << n << space << n - 2 << endll;
        cout << n - 1 << space << n - 1 << endll;
        for (int i = n - 3; i >= 1; i--) {
            cout << nxt << space << i << endll;
            nxt = (nxt + i+1) / 2;
        }
       // cout << nxt <<endl;
    }
}

int main() {
    //freopen("hello.in", "r", stdin);
    //  freopen("out.txt", "w", stdout);
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