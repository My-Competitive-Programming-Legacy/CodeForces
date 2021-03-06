#include <iostream>
#include <vector>
#include <algorithm>
#include "math.h"
#include "unordered_map"
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
typedef long double ld;
#define debug(val) "[ " << #val " : " << (val)
#define space " "
#define vi vector<int>
#define PI (double)(atan(1)*4)
#define pb push_back
#define pi pair<int , int >
#define ff first
#define ss second
#define INF 2000000000
vi dx = {-1, 0, 0, 1};
vi dy = {0, -1, 1, 0};

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res = "";
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if ((int) st.size() % 2 == 0) res.push_back('1');
            else res.pb('0');
            st.push(res.back() - '0');
        } else {
            res.push_back((char) ('0' + st.top()));
            st.pop();
        }
    }
    cout << res << endl;

}

//#define _DEBUG

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q = 1;
    //  cin >> q;
    for (int i = 1; i <= q; i++) {
       // cout << "Case #" << i << ": ";
        solve();
    }
}