#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a = 0, b = 0, c = 0;
    int g;
    for (int i = 0; i < n; ++i) {
        cin >> g;
        if (g > 0)a++;
        else if (g < 0)b++;
        else c++;
    }
    if (a >= (n + 1) / 2)cout << 1;
    else if (b >= (n + 1) / 2)cout << -1;
    else cout << 0;
    return 0;
}