#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <time.h>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back
#define MOD (int)(1e9  + 7)

int main() {
    int q;
    cin >> q;
    while(q -- ) {
       int n , a ,b ;
       cin >> n >> a >> b ;
       int nxt = 0 ;
       string ans = "" ;
       for(int i = 0 ; i < n ; i++ ){
           ans += (char)(((int)'a' + nxt)) ;
           nxt++;
           nxt %=b ;
       }
       cout << ans << endl;
    }
    return 0;

}