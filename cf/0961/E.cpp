#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;
int arr[MAXN];

struct BIT {
    ll data[MAXN];
    void update(int pos, int val){
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
}ds;
vector<pii> to_update[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll ans = 0;

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        arr[a] = min(arr[a], N);

        for(pii p : to_update[a]){
            ds.update(p.first, p.second);
        }
        ans += ds.query(arr[a]);
        if(arr[a] > a){
            to_update[a+1].push_back(pii(a, 1));
            to_update[arr[a] + 1].push_back(pii(a, -1));
        }
    }
    cout << ans;
}

