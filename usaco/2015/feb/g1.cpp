#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 755;
const ll mod = 1e9 + 7;

int R, C, K;

int arr[MAXN][MAXN];

vector<int> pos[MAXN * MAXN];

vector<ll> BIT[MAXN * MAXN];

void BIT_update(int tp, int pos, ll val){
    while(pos < (int)BIT[tp].size()){
        BIT[tp][pos] += val;
        BIT[tp][pos] %= mod;

        pos += pos & -pos;
    }
}

ll BIT_query(int tp, int pos){
    ll ans = 0;
    while(pos){
        ans += BIT[tp][pos];
        ans %= mod;

        pos -= pos & -pos;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);

    cin >> R >> C >> K;
    for(int a = 1; a <= R; a++){
        for(int b = 1; b <= C; b++){
            cin >> arr[a][b];
            pos[arr[a][b]].push_back(b);
        }
    }

    BIT[0] = vector<ll>(MAXN);
    for(int a = 1; a <= K; a++){
        pos[a].push_back(0);
        sort(allof(pos[a]));
        pos[a].erase(unique(allof(pos[a])), pos[a].end());
        BIT[a] = vector<ll>(pos[a].size() + 1);
    }

    ll last_ans = 0;
    for(int a = 1; a <= R; a++){
        vector<pair<pll, ll>> updates;
        for(int b = 1; b <= C; b++){
            int val = arr[a][b];
            int idx = lower_bound(allof(pos[val]), b) - pos[val].begin();
            ll p1 = BIT_query(0, b - 1);
            ll p2 = BIT_query(val, idx - 1);
            ll before = 0;
            if(a == 1 && b == 1){
                before = 1; //hardcode lol
            } else {
                before = p1 - p2;
            }

            before %= mod;
            if (before < 0){
                before += mod;
            }
            last_ans = before;


            updates.push_back({{val, idx}, before});
            assert(pos[val][idx] == b);
        }
        for(pair<pll, ll> p : updates){
            BIT_update(p.first.first, p.first.second, p.second);
            BIT_update(0, pos[p.first.first][p.first.second], p.second);
        }
    }
    cout << last_ans;
}
