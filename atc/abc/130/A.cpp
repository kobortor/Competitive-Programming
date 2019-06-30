#include<iostream>
#include<utility>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int x, a;
    cin >> x >> a;
    if (x < a) {
        cout << 0;
    } else {
        cout << 10;
    }
}
