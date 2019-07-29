#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int tri(int n) {
    return n * n;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    cout << tri(a1 + a2 + a3) - tri(a1) - tri(a3) - tri(a5);
}
