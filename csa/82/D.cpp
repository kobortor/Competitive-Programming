#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).beg(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9 + 7;

const int MAXN = 1e5 + 5;

int N, K;

int prv[MAXN];
int beg[MAXN];
int back[MAXN];
int rem[MAXN];
int used[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    memset(prv, 0xaf, sizeof prv);

    cin >> N >> K;
    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;

        if(a - prv[x] >= K){
            beg[x] = a;
            prv[x] = a;
            back[a] = a;
        }

        prv[x] = a;
        back[beg[x]] = a;
    }

    int lim = 0;
    int used = 0;
    for(int a = 1; a <= N; a++){
        used -= rem[a];

        if(back[a] != 0){
            used++;

            int end = back[a] + K;
            if(end <= N){
                rem[end]++;
            }

            lim = max(lim, used);
        }
    }

    used = 0;
    ll ans = 1;
    for(int a = 1; a <= N; a++){
        used -= rem[a];

        if(back[a] != 0){
            ans = (ll)ans * (lim - used) % mod;
            used++;
        }
    }

    cout << ans << "\n";
}
