#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;
const ll mod = 1e9 + 7;

int N, M, K;
ll row[MAXN];
ll col[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> K;
    for(int a = 1; a <= N; a++){
        row[a] = 1;
    }
    for(int a = 1; a <= M; a++){
        col[a] = 1;
    }
    while(K--){
        char ch;
        int X, Y;
        cin >> ch >> X >> Y;
        if(ch == 'R'){
            row[X] = row[X] * Y % mod;
        } else {
            col[X] = col[X] * Y % mod;
        }
    }
    ll colsum = 0;
    for(int a = 1; a <= M; a++){
        colsum += col[a];
    }
    colsum %= mod;

    ll tmpsum = 0;
    for(int a = 1; a <= M; a++){
        tmpsum += (ll)a * col[a]; 
        tmpsum %= mod;
    }

    ll ans = 0;
    for(int a = 1; a <= N; a++){
        ans += row[a] * tmpsum;
        ans %= mod;

        tmpsum += M * colsum;
        tmpsum %= mod;
    }
    cout << ans;
}
