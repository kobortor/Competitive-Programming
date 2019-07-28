#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;

    int ab = (int)round(sqrt(a * b / c));
    cout << 4 * (ab + a / ab + b / ab);
}
