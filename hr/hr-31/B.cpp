#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e4 + 4;

int N, K;

__float128 sol[MAXN];

bool check(__float128 x){
    __float128 tot = 0;
    for(int a = 0; a < K; a++){
        tot += min(sol[a], x);
    }
    return tot >= x * N;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 0; a < K; a++){
        double x;
        cin >> x;
        sol[a] = x;
    }

    __float128 lo = 0, hi = 1e10;
    for(int step = 0; step < 400; step++){
        __float128 mid = (lo + hi) / 2;
        if(check(mid)){
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(15) << (double)lo;
}
