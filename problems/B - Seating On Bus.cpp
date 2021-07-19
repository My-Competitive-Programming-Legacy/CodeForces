#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define ar array
#define space " "
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>

int main() {
    int n, m;
    cin >> n >> m;
    vii a(n, vi(4, 0));
    bool window = true;
    for (int i = 1; i <= m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (window) {
                if (a[j][0] == 0) {
                    a[j][0] = i;
                    break;
                } else if (a[j][3] == 0) {
                    a[j][3] = i;
                    if (j == 0) window = false;
                    break;
                }
            } else {
                if (a[j][1] == 0) {
                    a[j][1] = i;
                    break;
                } else if (a[j][2] == 0) {
                    a[j][2] = i;
                    break;
                }
            }
        }
    }
    vector<int> ans ;
    for (int i = n - 1; i >= 0; i--) {
            ans.push_back(a[i][1]);
            ans.push_back(a[i][0]);
            ans.push_back(a[i][2]);
            ans.push_back(a[i][3]);
    }
    for(auto v : ans){
        if(v != 0 ) cout << v << space ;
    }
    cout <<endl;


}