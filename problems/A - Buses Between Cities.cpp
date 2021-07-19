#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define ar array
#define space " "
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
const double inf = 2e18;
#define EPS  0.0000000001

void solve() {
    int a, ta, b, tb;
    cin >> a >> ta;
    cin >> b >> tb;
    string s;
    cin >> s;

    int start = (stoi(s.substr(0, 2))) * 60 + stoi(s.substr(3,2));
    int end= start + ta ;
    int ans =0;
    for (int i = 0; i <= 10000; i++) {
        int start2 = 300+i * b;
        int end2 = start2 + tb ;
        if(start2 > 1439)
            break;
        if(end > start2 && start < end2)ans++ ;

    }
    cout << ans <<endl;

}

int main() {
    int q = 1;
//    cin >> q;
    while (q--) {
        solve();
    }


}