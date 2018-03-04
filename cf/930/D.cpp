#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const int MAXX = 1e6 + 5;
const int offset = 5e5;

int N;

pll below[MAXX];
pll above[MAXX];

ll solve (const vector<pii> &points){
    vector<pll> abv, blw;

    for(pii p : points){
        //watch out for negatives
        if((p.first + p.second) % 2){
            p.second--;
        }

        pll np = pll((p.first + p.second), (p.first - p.second));
        abv.push_back(pll(np.first + 1, np.second));
        blw.push_back(pll(np.first - 1, np.second));
    }
    sort(allof(abv));
    sort(allof(blw));
    reverse(allof(blw));

    for(ll a = 0, idx = 0, minc = 1e9, maxc = -1e9; a < MAXX; a++){
        while(idx < (ll)abv.size() && abv[idx].first <= a - offset){
            minc = min(minc, abv[idx].second + 1);
            maxc = max(maxc, abv[idx].second - 1);
            idx++;
        }

        above[a] = pll(minc, maxc);
    }

    for(ll a = MAXX - 1, idx = 0, minc = 1e9, maxc = -1e9; a >= 0; a--){
        while(idx < (ll)blw.size() && blw[idx].first >= a - offset){
            minc = min(minc, blw[idx].second + 1);
            maxc = max(maxc, blw[idx].second - 1);
            idx++;
        }

        below[a] = pll(minc, maxc);
    }

    ll ans = 0;
    for(int a = 0; a < MAXX; a++){
        ll lft = max(above[a].first, below[a].first);
        ll rht = min(above[a].second, below[a].second);
        ll ht = a - offset;

        if(lft > rht || ht % 2 == 0){
            continue;
        }

        ans += (rht - lft) / 2 + 1;
    }

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    if(N < 4){
        cout << 0;
        return 0;
    }

    //to block, the parity of the x+y coordinate of the black piece must be different from the white piece

    vector<pii> odds, evens;
    for(int a = 0; a < N; a++){
        pii point;
        cin >> point.first;
        cin >> point.second;
        if((point.first + point.second) % 2){
            odds.push_back(point);
        } else {
            evens.push_back(point);
        }
    }

    ll ans = 0;
    ans += solve(odds);
    ans += solve(evens);
    cout << ans;
}
