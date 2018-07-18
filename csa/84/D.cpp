#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll MAXN = 1e5 + 5;

ll N, K;

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
} cntL, cntR, sumL, sumR;

vector<int> uniqL, uniqR;
map<int, vector<int>> points;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    uniqL.push_back(-1e9);
    uniqR.push_back(-1e9);
    
    cin >> N >> K;
    for(int a = 1; a <= N; a++){
        int x, y;
        cin >> x >> y;
        points[x].push_back(y);

        uniqL.push_back(-(x - y));
        uniqR.push_back(x + y);
    }

    sort(allof(uniqL));
    sort(allof(uniqR));

    uniqL.erase(unique(allof(uniqL)), uniqL.end());
    uniqR.erase(unique(allof(uniqR)), uniqR.end());

    for(auto &au : points){
        for(int i : au.second){
            int id = lower_bound(allof(uniqR), au.first + i) - uniqR.begin();
            cntR.update(id, 1);
            sumR.update(id, au.first + i);
        }
    }

    ll ans = 1e18;

    for(auto &au : points){
        int xpos = au.first;
        vector<int> &vec = au.second;

        for(int i : vec){
            int idL = lower_bound(allof(uniqL), -(xpos - i)) - uniqL.begin();
            int idR = lower_bound(allof(uniqR), xpos + i) - uniqR.begin();

            cntR.update(idR, -1);
            sumR.update(idR, -(xpos + i));

            cntL.update(idL, +1);
            sumL.update(idL, xpos - i);
        }

        int lo = 0, hi = 1e9;
        while(lo <= hi){
            int mid = (lo + hi) / 2;

            int idL = upper_bound(allof(uniqL), -(xpos - mid)) - uniqL.begin() - 1;
            int idR = upper_bound(allof(uniqR), xpos + mid) - uniqR.begin() - 1;

            int totcnt = cntL.query(idL) + cntR.query(idR);

            if(totcnt < K){
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        int idL = upper_bound(allof(uniqL), -(xpos - lo)) - uniqL.begin() - 1;
        int idR = upper_bound(allof(uniqR), xpos + lo) - uniqR.begin() - 1;       

        int totcnt = cntL.query(idL) + cntR.query(idR);

        ll totdist = (cntL.query(idL) * xpos - sumL.query(idL)) + (sumR.query(idR) - cntR.query(idR) * xpos);

        ans = min(ans, totdist - (ll)(totcnt - K) * lo);
    }

    cout << ans;
}
