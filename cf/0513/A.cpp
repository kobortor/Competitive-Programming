#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;

    if (n1 <= n2) {
        cout << "Second";
    } else {
        cout << "First";
    }
}
