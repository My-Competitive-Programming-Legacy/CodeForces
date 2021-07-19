#include <iostream>

using namespace std;
#define E 10
int a[1000 + E];

int main() {
    int r, c;
    cin >> r >> c;
    char a[r + E][c + E];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            if (a[i][j] == '.') a[i][j] = 'D';
        }
    bool ok = false;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a[i][j] == 'W') {
                if (i > 0) ok |= a[i - 1][j] == 'S';
                if (i < r - 1) ok |= a[i + 1][j] == 'S';
                if (j > 0) ok |= a[i][j - 1] == 'S';
                if (j < c - 1) ok |= a[i][j + 1] == 'S';
            }


        }
    }
    if (ok) cout << "No";
    else {
        cout << "Yes" << endl;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; ++j) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}