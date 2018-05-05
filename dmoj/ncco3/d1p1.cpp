#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

set<pii> house;

pii get_bound(const map<int, int> &mp){
    int lo = 1e9, hi = -1e9;
    int lft = 0, rht = 0;

    for(pii p : mp) rht += p.second;

    for(pii p : mp){
        rht -= p.second;

        if(lft + p.second >= rht && lft <= rht + p.second){
            lo = min(lo, p.first);
            hi = max(hi, p.first);
        }

        lft += p.second;
    }
    return {lo, hi};
}

ll get_dist(int x, int y){
    ll ans = 0;
    for(pii p : house){
        ans += abs(p.first - x);
        ans += abs(p.second - y);
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    map<int, int> houseX, houseY;

    cin >> N;
    for(int a = 1; a <= N; a++){
        int x, y;
        cin >> x >> y;
        house.insert({x, y});
        houseX[x]++;
        houseY[y]++;
    }

    pii bndx = get_bound(houseX);
    pii bndy = get_bound(houseY);

    if(bndx.first == bndx.second && bndy.first == bndy.second && house.count({bndx.first, bndy.first})){
        int xpos = bndx.first;
        int ypos = bndy.first;

        ll costX = get_dist(xpos + 1, ypos);
        ll costY = get_dist(xpos, ypos + 1);

        ll cnt = 0;
        if(costX <= costY){
            cnt += 2;
        }

        if(costY <= costX){
            cnt += 2;
        }

        cout << min(costX, costY) << " " << cnt << "\n";
    } else {
        ll ans = ll(bndx.second - bndx.first + 1) * (bndy.second - bndy.first + 1);
        for(pii p : house){
            if(bndx.first <= p.first && p.first <= bndx.second){
                if(bndy.first <= p.second && p.second <= bndy.second){
                    ans--;
                }
            }
        }
        cout << get_dist(bndx.first, bndy.first) << " " << ans << "\n";
    }
}
