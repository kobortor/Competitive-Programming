#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;

    cout << 2 * (h1 + h2 + w1 + 2);
}
