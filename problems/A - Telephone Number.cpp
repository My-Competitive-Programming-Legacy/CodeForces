#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  unsigned long long ull;
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
string str1, str2;
const int N = 23;
int main(){
    int t ;
    cin>>t;
    while (t--) {
        int n;
        cin >> n;
        string num;
        cin >> num;
        bool be = false;
        for (int i = 0; i < n; i++) {
            if (be == false) {
                if (num[i] == '8' && (n - i) >= 11)be = true;
            }
        }
        if(be ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}