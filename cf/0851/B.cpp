#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    pll A, B, C;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;

    pll AB = {B.first - A.first, B.second - A.second};
    pll BC = {C.first - B.first, C.second - B.second};

    if (bool(AB.first) == bool(BC.first) && AB.first * BC.second == AB.second * BC.first) {
        cout << "No";
    } else {
        ll dAB = AB.first * AB.first + AB.second * AB.second;
        ll dBC = BC.first * BC.first + BC.second * BC.second;

        if (dAB == dBC) {
            cout << "Yes";
        } else {
            cout << "No";
        }
    }

}
