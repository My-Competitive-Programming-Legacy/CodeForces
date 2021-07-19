#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long int ll;
#define space " "
#define vi vector<int>
#define pb push_back

int one(int &x) {
    if (x > 0) {
        x--;
        return 1;
    }
    return 0;
}

int two(int &x, int &y) {
    if (x > 0 && y > 0) {
        x--;
        y--;
        return 1;
    }
    return 0;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        vi arr = {a, b, c};
        sort(arr.begin(), arr.end() , greater<>());
        int res = 0;
        res += one(arr[0]);
        res += one(arr[1]);
        res += one(arr[2]);
        res += two(arr[0], arr[1]);
        res += two(arr[0], arr[2]) ;
        res += two(arr[1], arr[2]);
        if (arr[0] > 0 && arr[1] > 0 && arr[2] > 0) res++;
        cout << res << endl;
    }


    return 0;
}