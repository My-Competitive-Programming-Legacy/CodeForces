#include <iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define E 10
#define MAX 200000+10
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q ;
    cin >> q ;
    while (q--)  {
        int a ,b ,c,n ;
        cin >>a >> b >> c >> n ;
        int m = max(a , max(b,c )) ;
        if((a+b+c+n)/3 >= m && (a+b+c+n)%3 == 0 ) cout << "YES" << endl ;
        else cout << "NO" << endl ;

    }
    return 0;
}