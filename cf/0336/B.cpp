#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll M, R;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> M >> R;

    double ans = 2 * M * M;

    ans += 2 * (M - 1) * sqrt(2);

    //dist > 1
    for(int a = 1; a <= M; a++){
        ll lft = a - 1;
        ll rht = M - a;

        if(lft > 1){
            ans += 2 * (lft - 1) * sqrt(2);
            ans += (lft - 1) * (lft - 2);
        }

        if(rht > 1){
            ans += 2 * (rht - 1) * sqrt(2);
            ans += (rht - 1) * (rht - 2);
        }
    }

    ans *= R;

    cout << fixed << setprecision(15) << ans / (M * M);
}
