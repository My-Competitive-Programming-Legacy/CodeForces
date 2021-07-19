#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
int q ;
//cout << pow(2 , 60 ) ;
cin >>q ;
while(q--){
    long long n ;
    long long sum = 0 , zor = 0 ;
    cin >> n ;
    for(int i = 0 ; i < n ; ++i) {
        long long  a ;
        cin >> a;
        sum += a ;
        zor ^= a ;
    }
    cout << 2 << endl ;
    cout << zor << " " << sum+zor << endl ;  
    
}
return 0 ;
}