#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

ll N, D, B;
ll stu[MAXN];
ll filled[MAXN];

//is it possible to only fail so many
bool check(ll X){
    ll L = X + 1;
    ll R = N - X;

    memset(filled, 0, sizeof filled);

    for(ll a = 1, idx = L; a <= (N + 1) / 2; a++){
        ll cnt = stu[a];
        while(cnt){
            if(idx > R){
                break;
            }
            if(idx * D < (a - idx)){
                idx++;
                continue;
            }
            if((N - idx + 1) * D < (idx - a)){
                break;
            }
            if(filled[idx] + cnt >= B){
                cnt -= B - filled[idx];
                filled[idx] = B;
                idx++;
            } else {
                filled[idx] += cnt;
                cnt = 0;
            }
        }
    }
    for(ll a = N, idx = R; a > (N + 1) / 2; a--){
        ll cnt = stu[a];
        while(cnt){
            if(idx < L){
                break;
            }
            if((N - idx + 1) * D < (idx - a)){
                idx--;
                continue;
            }
            if(idx * D < (a - idx)){
                break;
            }
            if(filled[idx] + cnt >= B){
                cnt -= B - filled[idx];
                filled[idx] = B;
                idx--;
            } else {
                filled[idx] += cnt;
                cnt = 0;
            }
        }
    }
    for(ll a = L; a <= R; a++){
        if(filled[a] < B){
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> D >> B;
    for(int a = 1; a <= N; a++){
        cin >> stu[a];
    }
    ll lo = 0, hi = (N + 1) / 2;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo;
}
