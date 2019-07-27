#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for (int a = 1; a <= 5; a++) {
        for (int b = 1; b <= 5; b++) {
            int x;
            cin >> x;
            if (x == 1) {
                cout << abs(a - 3) + abs(b - 3);
            }
        }
    }
}
