#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 55;

int N, K;
ll book[MAXN];
bool good[MAXN][MAXN];

bool solve(ll req){
    memset(good, 0, sizeof good);
    good[0][0] = true;
    for(int i = 1; i <= K; i++){
        for(int a = 1; a <= N; a++){
            ll sum = 0;
            for(int b = a; b >= 1; b--){
                sum += book[b];
                if((sum & req) == req){
                    good[a][i] |= good[b - 1][i - 1];
                }
            }
        }
    }
    return good[N][K];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    for(int a = 1; a <= N; a++){
        cin >> book[a];
    }

    ll ans = 0;
    for(ll a = 62; a >= 0; a--){
        if(solve(ans | (1ll << a))){
            ans |= 1ll << a;
        }
    }

    cout << ans;
}
