#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;

#define pb push_back
#define mp make_pair
#define mt make_tuple

#define f first
#define s second
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
#define N (int)(1e5)
using namespace std;
//map<int, int> fen[N + E];
map<int , map<int , int >> fen ;

void update(int i, int delta, int val) {
    for (; i < MAX; i = i | (i + 1)) {
        fen[i][val] += delta;
    }
}
int sum(int r, int val) {
    int res = 0;
    for (; r > 0; r = (r & (r + 1) )- 1  ) {
        if (fen[r].count(val))
            res += fen[r][val];
    }
    return res;
}
int main() {
    IO;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if(i == 7) {
            int x = 8  ;
        }
        int a, t, x;
        cin >> a >> t >> x;
        if (a == 1) {
            update(t, 1, x);
        } else if (a == 2) {
            update(t, -1, x);
        } else {
            cout << sum(t, x) << endl;
        }
    }


    return 0;


}