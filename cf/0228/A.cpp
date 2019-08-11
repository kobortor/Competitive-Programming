#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    set<int> s;
    for (int a = 0, x; a < 4; a++) {
        cin >> x;
        s.insert(x);
    }

    cout << 4 - s.size();
}
