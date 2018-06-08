#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, M;
ll box[MAXN];
ll tmp[MAXN];

bool good(ll tm){
    copy(box, box + N + 1, tmp);

    ll back = N;
    for(ll a = 0; a < M; a++){
        while(back > 0 && tmp[back] == 0){
            back--;
        }

        ll avail = tm - back;
        while(back > 0){
            if(tmp[back] <= avail){
                avail -= tmp[back];
                tmp[back] = 0;
                back--;
            } else {
                tmp[back] -= avail;
                break;
            }
        }
    }

    return back == 0;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> box[a];
    }

    ll lo = 0, hi = 1e15;

    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(!good(mid)){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    cout << lo;
}
