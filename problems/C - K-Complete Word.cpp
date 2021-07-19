#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int diffSz = (k + 1) / 2;
        int f[diffSz + 2][27];
        for (int i = 0; i <= diffSz; i++) {
            for (int j = 0; j < 26; j++) {
                f[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            int chr = s[i] - 'a';
            if (k % 2 == 0) {
                int idx = i % k ;
                if(i % k >= (k/2) ){
                    f[k - idx - 1][chr] ++ ;
                }else {
                    f[idx][chr]++ ;
                }
            } else {
                int idx = i % k;
                if (idx == k / 2) f[idx][chr]++;
                else if (idx > k / 2) f[k - idx - 1 ][chr]++;
                else f[idx][chr]++;
            }
        }
        int ans = 0;
        for (int i = 0; i <= diffSz; i++) {
            int maxNum = 0;
            int sum = 0;
            for (int j = 0; j < 26; j++) {
                sum += f[i][j];
                if (f[i][j] > maxNum) maxNum = f[i][j];
            }
            ans += (sum - maxNum);
        }
        cout << ans << endl;

    }
    return 0;

}