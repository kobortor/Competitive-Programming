#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int Y, W;
    cin >> Y >> W;

    int mx = max(Y, W);
    switch (mx) {
        case 1: cout << "1/1"; break;
        case 2: cout << "5/6"; break;
        case 3: cout << "2/3"; break;
        case 4: cout << "1/2"; break;
        case 5: cout << "1/3"; break;
        case 6: cout << "1/6"; break;
    }
}
