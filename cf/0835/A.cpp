#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;

    int x1 = v1 * s + 2 * t1;
    int x2 = v2 * s + 2 * t2;

    if (x1 == x2) {
        cout << "Friendship";
    } else if (x1 < x2) {
        cout << "First";
    } else {
        cout << "Second";
    }
}
