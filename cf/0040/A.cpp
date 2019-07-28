#include<bits/stdc++.h>
 
using namespace std;
 
#define allof(x) (x).begin(), (x).end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 
 
 
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
 
    int x, y;
    cin >> x >> y;
    int r = sqrt(x*x + y*y);
 
    if (x * y >= 0) {
        if (r % 2 == 0) {
            cout << "black";
            return 0;
        }
    }
 
    if (x * y <= 0) {
        if (r % 2 == 1) {
            cout << "black";
            return 0;
        }
    }
 
    if (r * r == x * x + y * y) {
        cout << "black";
        return 0;
    }
 
    cout << "white";
}
