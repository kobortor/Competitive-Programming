#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, X;
ll Q[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> X;

    ll sum = 0;
    for(int a = 0; a < N; a++){
        cin >> Q[a];
        sum += Q[a];
    }

    ll num_bottles = (sum + X - 1) / X;

    sort(Q, Q + N);
    reverse(Q, Q + N);

    ll remain = 0;
    for(int a = num_bottles; a < N; a++){
        remain += Q[a];
    }

    cout << num_bottles << " ";

    ll cur_tm = 0;
    
    for(ll filled = 0; filled < num_bottles; filled++){
        ll avail = X - Q[filled] - cur_tm;

        ll req = (remain + num_bottles - filled - 1) / (num_bottles - filled);
        if(req > avail){
            cur_tm += avail;
            remain -= avail * (num_bottles - filled);
        } else {
            cout << max(Q[num_bottles], cur_tm + req);
            break;
        }
    }
}
