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
#define linebreak "\n"
#define space " "
#define E 10
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
using namespace std;


/**Global stuff */

/**Global stuff */

int main() {
    int n;
    cin >> n;
    int pre[n + E];
    int post[n + E];
    int arr[n + E];
    int bits = 0 ;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
       bits  = max (bits , (int)log2(arr[i])+1) ;
    }
    for (int i = 0; i < n; i++) {
        int t =  ( (1<<bits) - 1) ^ arr[i] ;
        //cout << t << endl ;
        if (i > 0)
            pre[i] = t & pre[i - 1];
        else
            pre[i] =t;
    }
    for (int i = n - 1; i >= 0; i--) {
        int t =  ( (1 << bits) - 1) ^ arr[i] ;
        if (i == n - 1)
            post[i] = t;
        else
            post[i] = t & post[i + 1];
    }
    int val = -1;
    int key = -1;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if ((arr[i] & post[i + 1]) > val) {
                val = arr[i] & post[i + 1];
                key = arr[i];
            }
        } else if (i == n - 1) {
            if ((arr[i] & pre[i - 1]) > val) {
                val = arr[i] & pre[i - 1];
                key = arr[i];
            }
        } else if ((arr[i] & post[i + 1] & pre[i - 1]) > val) {
            val = arr[i] & post[i + 1] & pre[i - 1];
            key = arr[i];
        }

    }
    cout << key << space;
    for (int i = 0, c = 1; i < n; i++) {
        if (c & arr[i] == key) c = 0;
        else cout << arr[i] << space;
    }

    return 0;


}