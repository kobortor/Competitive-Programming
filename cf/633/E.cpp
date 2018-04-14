#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

int N, K;

int vis[MAXN];
int rev[MAXN];

ll best[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    for(int a = 0; a < N; a++){
        cin >> vis[a];
        vis[a] *= 100;
    }
    for(int a = 0; a < N; a++){
        cin >> rev[a];
    }

    deque<pii> dqv, dqr;

    for(int a = 0, idx = 0; a < N; a++){
        if(!dqv.empty() && dqv[0].first < a){
            dqv.pop_front();
        }
        if(!dqr.empty() && dqr[0].first < a){
            dqr.pop_front();
        }

        while(idx < N){
            if(!dqv.empty() && !dqr.empty()){
                ll cur = min(dqv[0].second, dqr[0].second);
                ll nxt = min(max(dqv[0].second, vis[idx]), min(dqr[0].second, rev[idx]));
                if(dqv[0].second > dqr[0].second){
                    break;
                }
                if(max(dqv[0].second, vis[idx]) > min(dqr[0].second, rev[idx]) && nxt < cur){
                    break;
                }
            }

            while(!dqv.empty() && dqv.back().second <= vis[idx]){
                dqv.pop_back();
            }

            while(!dqr.empty() && dqr.back().second >= rev[idx]){
                dqr.pop_back();
            }
            dqv.push_back(pii(idx, vis[idx]));
            dqr.push_back(pii(idx, rev[idx]));
            idx++;
        }
        best[a] = min(dqv[0].second, dqr[0].second);
    }

    sort(best, best + N);
    double chance = (double)K / N;
    double ans = 0;

    for(int a = 0; a + K - 1 < N; a++){
        ans += chance * best[a];
        chance *= N - K - a;
        chance /= N - a - 1;
    }

    cout << fixed << setprecision(15) << ans;
}
