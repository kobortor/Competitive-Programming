#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll ans = 1;

void test(int x){
    cout << "Q " << x << endl;
    int tmp;
    cin >> tmp;
    while(tmp--){
        ans *= x;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    test(2);
    test(3);
    test(5);
    test(7);

    cout << "A " << ans << endl;
}
