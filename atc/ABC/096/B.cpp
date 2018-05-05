#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll A, B, C;

    cin >> A >> B >> C;
    ll best = max(A, max(B, C));

    ll K;
    cin >> K;
    while(K--){
        best *= 2;
    }
    cout << A + B + C + best - max(A, max(B, C));
}
