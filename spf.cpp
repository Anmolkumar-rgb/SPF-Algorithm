
#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e6;
int spf[N+1];
bool isprime[N+1];

void sieve() {
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;

    for(int i = 2; i*i <= N; i++) {
        if(isprime[i]) {
            spf[i] = i;

            for(int j = i*i; j <= N; j += i) {
                if(isprime[j]) {
                    isprime[j] = false;

                    if(spf[j] == 0) {
                        spf[j] = i;
                    }
                }
            }
        }
    }

    // by observation we have seen the spf prime number is itself.
    for(int i = 2; i <= N; i++) {
        if(isprime[i]) {
            spf[i] = i;
        }
    }
}

void prime_factor(int n) {
    while(n > 1) {
        cout << spf[n] << " ";
        n = n / spf[n];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;
        prime_factor(n);
    }

    return 0;
}
