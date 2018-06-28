#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int K, N, S, P;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> K >> N >> S >> P;
    cout << ((N+S-1)/S*K+P-1)/P;
}
