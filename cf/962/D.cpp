#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1.5e5 + 5;

priority_queue<ll, vector<ll>, greater<ll>> pq;
unordered_map<ll, set<ll>> lst;
ll out[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N;
    cin >> N;
    for(ll a = 1; a <= N; a++){
        ll x;
        cin >> x;

        auto &au = lst[x];
        au.insert(a);
        if((int)au.size() == 2){
            pq.push(x);
        }
    }
    while(!pq.empty()){
        ll top = pq.top();

        auto &au = lst[top];
        au.erase(au.begin());

        ll pos = *au.begin();
        au.erase(au.begin());

        if((int)au.size() <= 1){
            pq.pop();
        }

        auto &au2 = lst[top * 2];
        au2.insert(pos);
        if((int)au2.size() == 2){
            pq.push(top * 2);
        }
    }
    memset(out, -1, sizeof out);
    ll sz = 0;
    for(auto au : lst){
        for(ll i : au.second){
            out[i] = au.first;
            sz++;
        }
    }
    cout << sz << "\n";
    for(ll a = 1; a <= N; a++){
        if(out[a] != -1){
            cout << out[a] << " ";
        }
    }
}
