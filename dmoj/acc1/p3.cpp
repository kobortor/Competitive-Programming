#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;
const ll mod = 998244353;
const ll inv = 499122177;

int N;
ll T;

pll food[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> T;

    for(int a = 0; a < N; a++){
        cin >> food[a].first >> food[a].second;
    }

    ll lo = 0, hi = 2e18;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        ll money = T;

        bool good = true;
        for(int a = 0; a < N; a++){
            if(food[a].first >= mid){
                money -= (food[a].first - mid) / food[a].second + 1;
                if(money < 0){
                    good = false;
                    break;
                }
            }
        }

        if(good){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    ll money = T;
    ll happ = 0;

    priority_queue<ll> pq;
    for(int a = 0; a < N; a++){
        if(food[a].first >= lo){
            ll iters = (food[a].first - lo) / food[a].second + 1;
            money -= iters;

            ll mi = iters % mod;
            
            happ += (food[a].first % mod) * mi % mod;
            happ -= food[a].second % mod * mi % mod * (mi - 1) % mod * inv % mod;

            happ %= mod;

            if(happ < 0){
                happ += mod;
            }

            pq.push(food[a].first - iters * food[a].second);
        } else {
            pq.push(food[a].first);
        }
    }

    while(money && !pq.empty() && pq.top() > 0){
        happ += pq.top();
        happ %= mod;
        money--;
        pq.pop();
    }

    cout << happ << endl;
}
