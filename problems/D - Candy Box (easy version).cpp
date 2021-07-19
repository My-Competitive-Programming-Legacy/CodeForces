#include <iostream>
#include<bits/stdc++.h>

using namespace std;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int a[n+10];
        for (int i = 0; i <n+1; i++) {
            a[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            a[tmp]++;
        }
        sort(a, a + n+1, greater<int>());
        int res = 0;
        unordered_set<int> freq;
        for (int i = 0; i < n && a[i] != 0 ; i++) {
            if (!freq.count(a[i])) {
                res += a[i] ;
                freq.insert(a[i]);
            } else {
                while (freq.count(a[i])) {
                    a[i]--;
                }
                if (a[i] <= 0) break;
                res += a[i];
                freq.insert(a[i]);
            }
        }
        cout << res << endl;
    }


    return 0;
}