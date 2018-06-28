#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
vector<vector<ll>> pointB, pointR;
vector<ll> mid;

ll calc_gap(ll first, vector<ll> &vec, ll last){
    ll prv = first;
    ll best = 1;
    for(ll x : vec){
        best = max(best, x - prv);
        prv = x;
    }
    return max(best, last - prv);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    pointB.emplace_back();
    pointR.emplace_back();

    bool hasB = false;
    bool hasR = false;

    for(int a = 1; a <= N; a++){
        ll x;
        cin >> x;
        char tp;
        cin >> tp;
        if(tp == 'B'){
            pointB.back().push_back(x);
            hasB = true;
        } else if (tp == 'R') {
            pointR.back().push_back(x);
            hasR = true;
        } else {
            pointB.emplace_back();
            pointR.emplace_back();
            mid.push_back(x);
        }
    }

    ll ans = 0;
    if(mid.empty()){
        if(!pointB[0].empty()){
            ans += pointB[0].back() - pointB[0][0];
        }
        if(!pointR[0].empty()){
            ans += pointR[0].back() - pointR[0][0];
        }
        cout << ans;
        return 0;
    }

    for(int a = 0; a < (int)mid.size() - 1; a++){
        ll g1 = calc_gap(mid[a], pointB[a + 1], mid[a + 1]);
        ll g2 = calc_gap(mid[a], pointR[a + 1], mid[a + 1]);

        ans += min(2 * (mid[a + 1] - mid[a]), 3 * (mid[a + 1] - mid[a]) - g1 - g2);
    }
    if(!pointB[0].empty()){
        ans += mid[0] - pointB[0][0];
    }
    if(!pointR[0].empty()){
        ans += mid[0] - pointR[0][0];
    }
    if(!pointB.back().empty()){
        ans += pointB.back().back() - mid.back();
    }
    if(!pointR.back().empty()){
        ans += pointR.back().back() - mid.back();
    }
    cout << ans;
    
}
