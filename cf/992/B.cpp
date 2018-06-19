#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int gcd(int x, int y){
    while(x % y){
        x %= y;
        swap(x, y);
    }
    return y;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int L, R, X, Y;
    cin >> L >> R >> X >> Y;

    int ans = 0;

    if(Y % X != 0){
        cout << 0;
    } else {
        Y /= X;
        for(int a = 1; a * a <= Y; a++){
            if(Y % a == 0){
                int b = Y / a;

                if(gcd(a, b) == 1 && L <= a * X && a * X <= R && L <= b * X && b * X <= R){
                    ans++;
                    if(a != b){
                        ans++;
                    }
                }
            }
        }
        cout << ans;
    }
}
