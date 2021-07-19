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
#include <memory.h>

using namespace std;
typedef long long int ll;
#define debug(val) "[ " << #val " : " << (val) << " ]\n"
#define space " "
#define vi vector<int>
#define PI atan(1)*4
#define pb push_back
#define pi pair<int , int >
const ll INF = LONG_LONG_MAX;

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    bool ok = false ;
    for(int i=0;i<n-1;i++){
        if(s[i] == '1' && s[i+1] == '0') ok = true ;
    }
    int i =0;
    while(s[i] == '0') {
        cout << s[i] ;
        i++;
    }
    if(ok) cout << '0' ;
    i = n-1;
    while(s[i] == '1') {
        cout << '1';
        i-- ;
    }
    cout << endl;
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