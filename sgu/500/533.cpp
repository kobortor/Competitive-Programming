#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    if (n <= 28 && n != 21) {
        cout << -1;
    } else if (n % 14 == 0 || n % 14 == 1 || n % 14 == 13) {
        cout << -1;
    } else {
        cout << n / 14;
    }
}
