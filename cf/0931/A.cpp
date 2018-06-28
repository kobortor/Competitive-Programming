#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int A, B;
    cin >> A >> B;

    int d1 = abs(B - A) / 2;
    int d2 = abs(B - A) - d1;

    cout << (d1 * (d1 + 1) + d2 * (d2 + 1)) / 2;
}
