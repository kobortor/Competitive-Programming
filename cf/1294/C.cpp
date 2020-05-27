#include<bits/stdc++.h>

// Created by kobortor On 23:59:38 on 26-05-2020

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int N = n;

        vector<int> primes;
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0) {
                primes.push_back(i);
                n /= i;
            }
        }
        if (n != 1) primes.push_back(n);

        sort(allof(primes));
        if (primes.front() == primes.back()) {
            if (primes.size() < 6) {
                cout << "NO\n";
            } else {
                int p = primes[0];
                cout << "YES\n";
                cout << p << " " << p * p << " " << N / (p * p * p) << "\n";
            }
        } else if (primes.size() < 3) {
            cout << "NO\n";
        } else if (primes.size() == 3) {
            if (primes[0] == primes[1] || primes[1] == primes[2]) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                cout << primes[0] << " " << primes[1] << " " << primes[2] << "\n";
            }
        } else {
            cout << "YES\n";
            cout << primes[0] << " " << primes.back() << " " << N / (primes[0] * primes.back()) << "\n";
        }
    }
}
