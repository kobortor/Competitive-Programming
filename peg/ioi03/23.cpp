#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXR = 30005;
const int MAXN = 5e5 + 5;

ll N, R;
pll origin;

vector<pll> rocks[MAXR];

void rot90(pll &p){
    p = pll(N - p.second, p.first);
}

ll prefix[MAXN];

ll rounddown(ll top, ll bot){
    if(bot < 0){
        top *= -1;
        bot *= -1;
    }

    if(top < 0){
        return (top - bot + 1)/ bot;
    } else {
        return top / bot;
    }
}

ll roundup(ll top, ll bot){
    if(bot < 0){
        top *= -1;
        bot *= -1;
    }

    if(top < 0){
        return top / bot;
    } else {
        return (top + bot - 1) / bot;
    }
}

ll solve(){
    memset(prefix, 0, sizeof prefix);

    for(int a = 1; a <= R; a++){
        for(int b = 1; b < (int)rocks[a].size(); b++){
            pll p1 = rocks[a][b - 1];
            pll p2 = rocks[a][b];

            if(p1.first == p2.first && p2.first == origin.first){
                if(p1.second < origin.second){
                    prefix[p1.first]++;
                    prefix[p1.first + 1]--;
                }
                continue;
            }

            if(p1.second >= origin.second && p2.second >= origin.second){
                continue;
            }

            //p1 comes before p2
            if((p1.first - origin.first) * (p2.second - origin.second) - (p1.second - origin.second) * (p2.first - origin.first) < 0){
                swap(p1, p2);
            }

            ll L, R;

            if(p1.second < origin.second){
                L = origin.first + roundup((p1.first - origin.first) * origin.second, origin.second - p1.second);
            } else {
                L = 1;
            }

            if(p2.second < origin.second){
                R = origin.first + rounddown((p2.first - origin.first) * origin.second, origin.second - p2.second);
            } else {
                R = N;
            }

            L = max(1ll, L);
            R = min(N, R);

            if(L <= R){
                prefix[L]++;
                prefix[R + 1]--;
            }
        }
    }

    ll ans = 0;
    for(int a = 1; a <= N; a++){
        prefix[a] += prefix[a - 1];
        if(prefix[a] == 0){
            ans++;
        }
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> R;
    cin >> origin.first >> origin.second;

    for(int a = 1; a <= R; a++){
        int cnt;
        cin >> cnt;
        for(int b = 1; b <= cnt; b++){
            pll p;
            cin >> p.first >> p.second;
            rocks[a].push_back(p);
        }
    }

    ll ans = 0;
    for(int cyc = 1; cyc <= 4; cyc++){
        ans += solve();

        rot90(origin);
        for(int a = 1; a <= R; a++){
            for(pll &p : rocks[a]){
                rot90(p);
            }
        }
    }

    cout << ans;
}
