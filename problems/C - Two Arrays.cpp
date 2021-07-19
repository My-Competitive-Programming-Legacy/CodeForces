#include <iostream>
typedef long long int ll;
using namespace std;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define space " "

ll  nCr[1100][1100];
int main() {
    int n, m;
    cin >> n >> m;
    nCr[0][0] = 0 ;
    for (int i = 1; i <= (n + 2 * m - 1); i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j || j == 0) nCr[i][j] = 1;
            else nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % (int)(1e9 + 7);
           // cout << "i = " << i << "  and   j = " << j << endl ;
           //if(i > 30 ) cout << nCr[29][29] << " at i = " << i << " and j = " << j << endl ;
        }
    }
    cout << nCr[n + 2 * m - 1][2*m] << endl;
    return 0;
}