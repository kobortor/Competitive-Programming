#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    int ans = 0;
    while (n--) {
        string s;
        cin >> s;
        if (s == "Tetrahedron") ans += 4;
        if (s == "Cube") ans += 6;
        if (s == "Octahedron") ans += 8;
        if (s == "Dodecahedron") ans += 12;
        if (s == "Icosahedron") ans += 20;
    }

    cout << ans;
}
