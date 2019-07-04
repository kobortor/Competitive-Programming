#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool isprime(int x) {
    for (int a = 2; a * a <= x; a++) {
        if (x % a == 0) {
            return false;
        }
    }

    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    int M = 1;
    while (isprime(N * M + 1)) M++;

    cout << M;
}
