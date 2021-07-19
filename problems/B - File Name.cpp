#include <iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define space " "

int main() {
    IO;
    int n;
    cin >> n;
    string a;
    cin >> a;
    int res = 0;
    for (int i = 2; i < n; i++) {
        if (a[i] == 'x' && a[i - 1] == 'x' && a[i - 2] == 'x') { res++; }
    }
    cout << res << endl;
}