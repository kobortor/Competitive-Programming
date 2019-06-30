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
    if (n % 3 == 2) {
        cout << "1 2 " << n - 3;
    } else {
        cout << "1 1 " << n - 2;
    }
}
