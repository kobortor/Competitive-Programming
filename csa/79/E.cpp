#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, K;

ll init = 0;
ll val[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 0; a < N; a++){
        cin >> val[a];
        if(val[a] < 0){
            val[a] *= -1;
            init += val[a];
        }
    }

    sort(val, val + N);

    multiset<ll> mst;
    mst.insert(0);
    for(int a = 1; a < K; a++){
        mst.insert(1e18);
    }

    vector<ll> planned;
    for(int a = 0; a < N; a++){
        planned.clear();
        ll last = *prev(mst.end());

        for(ll x : mst){
            if(x + val[a] < last){
                planned.push_back(x + val[a]);
            } else {
                break;
            }
        }

        for(ll x : planned){
            mst.insert(x);
            mst.erase(prev(mst.end()));
        }
    }

    for(ll x : mst){
        cout << x - init << "\n";
    }
}
