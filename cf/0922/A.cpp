#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int x, y;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> x >> y;
    if(y == 0 || x < (y - 1) || (x - (y - 1)) % 2 || (y == 1 && x > 0)){
        cout << "No";
    } else {
        cout << "Yes";
    }
}
