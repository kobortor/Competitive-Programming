#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, M;

vector<pll> days;
pll buildings[MAXN];
vector<ll> uniq;

struct BIT {
    ll data[MAXN];
    void update(int pos, ll val){
        while(pos < MAXN){
            data[pos] += val;
            pos += pos & -pos;
        }
    }

    ll query(int pos){
        ll ans = 0;
        while(pos){
            ans += data[pos];
            pos -= pos & -pos;
        }
        return ans;
    }
} ds;

map<ll, ll> blocks;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;

    ll sum = 0;

    uniq.push_back(-1);
    uniq.push_back(0);
    uniq.push_back(0x3f3f3f3f);

    days.push_back({0x3f3f3f3f, 0});

    for(int a = 0; a < N; a++){
        ll x;
        cin >> x;

        uniq.push_back(x);

        sum += x;
        
        while(days.back().first <= x){
            days.pop_back();
        }

        days.push_back({x, sum});
    }

    sort(allof(uniq));

    for(int a = 1; a < (int)days.size(); a++){
        days[a].first = lower_bound(allof(uniq), days[a].first) - uniq.begin();
        blocks[days[a].first] = days[a].second - days[a - 1].second;

        ds.update(days[a].first, days[a].second - days[a - 1].second);
    }

    for(int a = 0; a < M; a++){
        cin >> buildings[a].second;
    }
    for(int a = 0; a < M; a++){
        cin >> buildings[a].first;
    }

    sort(buildings, buildings + M);

    ll remain = sum;
    int ans = 0;

    for(int a = 0; a < M; a++){
        ll cost = buildings[a].first;
        ll wt = buildings[a].second;

        int id = lower_bound(allof(uniq), wt) - uniq.begin();

        ll below = ds.query(id - 1);

        if(remain - below >= cost){
            remain -= cost;
            auto iter = blocks.lower_bound(id);
            while(cost){
                if(iter->second <= cost){
                    ds.update(iter->first, -iter->second);
                    cost -= iter->second;

                    auto tmp = iter;
                    iter++;
                    blocks.erase(tmp);
                } else {
                    ds.update(iter->first, -cost);
                    iter->second -= cost;
                    cost = 0;
                }
            }
            ans++;
        }

    }
    cout << ans << "\n";
}
