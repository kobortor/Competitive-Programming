#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int A, B, C;
    cin >> A >> B >> C;
    cout << min(abs(A-C)+abs(A-B), abs(B-C)+abs(B-A));
}
