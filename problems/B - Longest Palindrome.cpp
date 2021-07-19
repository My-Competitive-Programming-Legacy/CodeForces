#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 10
#define ACCURATE cout << fixed << setprecision(20)
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
#define N (int)(1e7)
#define _DEBUG
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <iomanip>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 10
#define ACCURATE cout << fixed << setprecision(20)
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
#define N (int)(1e7)
#define _DEBUG
using namespace std;

int main() {
#ifdef _DEBUG // place in cmake-build-debug folder
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    IO;
    int n, m;
    cin >> n >> m;
    set<string> st;
    string s[n + E];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        st.insert(s[i]);
    }
    string res = "";
    for (int i = 0; i < n; i++) {
        reverse(s[i].begin(), s[i].end());
        for (int j = 0; j < n; j++) {
            if (i != j && s[j] == s[i]) {
                res += s[j];
            }
        }

    }
    string mid = "";
    int size = 0;
    for (int i = 0; i < n; i++) {
        int len = s[i].size();
        bool ok = true;
        for (int j = 0; j < len; j++) {
            if (s[i][j] != s[i][len - j -1 ])
                ok = false;
        }
        if (ok) {
            if (len > size) {
                size = len;
                mid = s[i];
            }
        }
    }
    cout << 2*res.size() + mid.size()<< endl;
    cout << res << mid;
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}