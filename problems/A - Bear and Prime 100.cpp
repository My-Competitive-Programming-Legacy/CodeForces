    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <set>
    #include <map>
    #include <stack>

    using namespace std;
    typedef long long int ll;
    #define space " "
    #define vi vector<int>
    #define pb push_back
    int s[200];

    int main() {
        vi primes;
        primes.push_back(4);
        primes.push_back(9);
        primes.push_back(25);
        primes.push_back(49);
        for (int i = 0; i < 200; i++) s[i] = 1;
        s[0] = 0;
        s[1] = 0;
        for (int i = 2; i <= 50; i++) {
            if (s[i] == 1) {
                primes.push_back(i);
                for (int j = i * i; j <= 50; j += i) {
                    s[j] = 0;
                }
            }
        }
        int divisors = 0;
        for (int i = 0; i < 19; i++) {
            printf("%d\n", primes[i]);
            fflush(stdout);
            char input[10];
            scanf("%s", input);
            if (input[0] == 'y' || input[0] == 'Y') {
                divisors++;
            }
            if (divisors > 1 || (divisors == 0 && i > 10)) break;

        }
        if (divisors < 2) {
            printf("prime\n");
            fflush(stdout);
        } else {
            printf("composite\n");
            fflush(stdout);
        }
        return 0;
    }