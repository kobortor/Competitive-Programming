#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int H, Q;

priority_queue<double> leaks;
vector<pair<double, double>> nxt;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> H >> Q;

    bool has_zero = false;
    for(int a = 0; a < Q; a++){
        double t, h;
        cin >> t >> h;

        if(h == 0){
            has_zero = true;
        }
        nxt.push_back({t, h});
    }
    sort(allof(nxt));

    if(!has_zero){
        cout << -1;
        return 0;
    }

    double curtime = 0;
    double curht = H;
    int idx = 0;

    while(curht > 0){
        double nxttime = 1e18;

        while(idx < Q && nxt[idx].first <= curtime){
            leaks.push(nxt[idx].second);
            idx++;
        }

        while(!leaks.empty() && leaks.top() > curht){
            leaks.pop();
        }

        bool changed = false;
        if(idx < Q){
            changed = true;
            nxttime = min(nxttime, nxt[idx].first);
        }

        if(!leaks.empty()){
            changed = true;
            nxttime = min(nxttime, curtime + (curht - leaks.top()) / leaks.size() + 1e-9);
        }

        if(!changed){
            cout << -1;
            return 0;
        }

        double leaked = (nxttime - curtime) * leaks.size();

        curtime = nxttime;
        curht -= leaked;
    }

    cout << fixed << setprecision(15) << curtime;
}
