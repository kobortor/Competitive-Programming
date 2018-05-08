#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1505;

int N;
pii pos[MAXN];

ll solve(vector<pii> &vec){
    ll ans = 0;
    sort(allof(vec), [](const pii &p1, const pii &p2) { return atan2f(p1.first, p1.second) < atan2f(p2.first, p2.second); });

    for(int a = 0, idx = 0; a < (int)vec.size(); a++){
        while(true){
            int nxt = (idx + 1) == (int)vec.size() ? 0 : idx + 1;
            ll dot = (ll)vec[nxt].first * vec[a].first + (ll)vec[nxt].second * vec[a].second;
            if(dot < 0){
                break;
            } else {
                idx = nxt;
            }
        }

        int nxt = (idx + 1) == vec.size() ? 0 : idx + 1;
        ll sz1 = abs((ll)vec[a].first * vec[idx].second - (ll)vec[a].second * vec[idx].first);
        ll sz2 = abs((ll)vec[a].first * vec[nxt].second - (ll)vec[a].second * vec[nxt].first);
        ans = max(ans, sz1);
        ans = max(ans, sz2);
    }
    return ans;
}

vector<pair<pair<pii, ll>, int>> points;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    points.reserve(1500 * 1500);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> pos[a].first >> pos[a].second;
        pos[a].first *= 2;
        pos[a].second *= 2;

        for(int b = 0; b < a; b++){
            pii mid = pii(pos[a].first + pos[b].first, pos[a].second + pos[b].second);
            mid.first /= 2;
            mid.second /= 2;
            
            ll dist = (pos[a].first - pos[b].first) * (pos[a].first - pos[b].first) + (pos[a].second - pos[b].second) * (pos[a].second - pos[b].second);

            points.push_back({{mid, dist}, a});
            points.push_back({{mid, dist}, b});
        }
    }
    sort(allof(points));

    vector<pii> vec;
    int idx = 0;
    ll ans = 0;
    while(idx < (int)points.size()){
        vec.clear();

        int nxt = idx;
        while(nxt < (int)points.size() && points[idx].first == points[nxt].first){
            pii mid = points[nxt].first.first;
            pii pt = pos[points[nxt].second];
            vec.push_back(pii(pt.first - mid.first, pt.second - mid.second));
            nxt++;
        }
        idx = nxt;
        ans = max(ans, solve(vec));
    }

    cout << ans / 2 << "\n";
}
