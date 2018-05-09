#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, A, B;

map<ll, map<ll, ll>> ump;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> A >> B;

    for(int a = 1; a <= N; a++){
        ll xi, vx, vy;
        cin >> xi >> vx >> vy;

        //products of (1, A) and (vx, vy)

        ll dot = vx + A * vy;
        ll cross = A * vx - vy;
        //cout << xi << " " << vx << " " << vy << " has cross " << cross << endl;

        ump[cross][dot]++;
    }

    ll ans = 0;
    for(auto &au : ump){
        ll sum = 0;
        for(pll p : au.second){
            sum += p.second;
            ans -= p.second * (p.second - 1);
        }
        ans += sum * (sum - 1);
    }
    cout << ans;
}
