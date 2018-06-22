#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K, S, T;

vector<pii> cars;
vector<int> stations, gaps;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> S >> T;

    while(N--){
        pii p;
        cin >> p.first >> p.second;
        cars.push_back(p);
    }

    sort(allof(cars));

    stations.push_back(0);
    stations.push_back(S);

    while(K--){
        int x;
        cin >> x;
        stations.push_back(x);
    }

    sort(allof(stations));

    for(int i = 1; i < (int)stations.size(); i++){
        gaps.push_back(stations[i] - stations[i - 1]);
    }

    sort(allof(gaps));

    ll cur_idx = 0;
    ll full_tm = 0;

    for(int a = 0; a < (int)cars.size(); a++){
        if(cars[a].second < gaps.back()){
            //cannot complete trip
            continue;
        }

        while(cur_idx < (int)gaps.size() && cars[a].second >= 2 * gaps[cur_idx]){
            full_tm += gaps[cur_idx];
            cur_idx++;
        }

        ll remain_cnt = gaps.size() - cur_idx;
        ll remain_gap = S - full_tm;

        ll cur_tm = 2 * remain_gap - (cars[a].second * remain_cnt - remain_gap);

        if(cur_tm + full_tm <= T){
            cout << cars[a].first;
            return 0;
        }
    }

    cout << -1;
}
