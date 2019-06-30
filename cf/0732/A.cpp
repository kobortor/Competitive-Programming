#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int k, r;
    cin >> k >> r;

    for (int a = 1; a <= 10; a++) {
        if (a * k % 10 == 0 || a * k % 10 == r) {
            cout << a;
            return 0;
        }
    }
}
