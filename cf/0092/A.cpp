#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    
    M %= N * (N + 1) / 2;

    for (int a = 1; a <= N; a++) {
        if (M < a) {
            cout << M;
            return 0;
        }

        M -= a;
    }
}
