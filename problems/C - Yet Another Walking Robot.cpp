#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <cmath>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 2e9+10
#define MOD (int)1e9
using namespace std;

int main() {
    IO;
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = '0' + s ;
        map<pair<int, int>, int> mp;
        int x = 0;
        int y = 0;
        int res = (int) 2e9;
        int st = 0;
        mp.insert(make_pair(make_pair(x, y), 0));

        for (int i = 1; i < (int) s.size(); i++) {
            if (s[i] == 'L') {
                x--;
            }
            if (s[i] == 'R') {
                x++;
            }
            if (s[i] == 'U') {
                y++;
            }
            if (s[i] == 'D') {
                y--;
            }
//            if (mp.count(make_pair(x, y))) {
//                int lastStart = mp.find(make_pair(x, y))->second;
//                if (abs(i+1 - lastStart ) < res) {
//                    res = abs(i - lastStart +1  );
//                    st = lastStart + 1 ;
//                }
//                mp.find(make_pair(x, y))->second = i;
//            } else {
//                mp.insert(make_pair(make_pair(x, y), i+1));
//            }
            if (mp.count(make_pair(x, y))) {
                int lastIdx  = mp.find(make_pair(x,y))->second ;
                int steps = i - lastIdx ;
                if(steps < res ) {
                    res = steps ;
                    st = lastIdx + 1 ;
                }
                mp.find(make_pair(x, y))->second = i;

            } else {
                mp.insert(make_pair(make_pair(x, y), i));
            }
        }
        if (res == (int) 2e9) cout << -1 << endl;
        else
            cout << st << space << res + st -1   << endl;
    }
}