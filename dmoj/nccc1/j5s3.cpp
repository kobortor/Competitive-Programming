#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    ll lo = 0, hi = N - 2;
    while(lo <= hi){
        //sum of N-1, N-2, N-3...
        ll mid = (lo + hi) / 2;
        ll sum = N * mid - mid * (mid + 1) / 2;
        if(2 * sum < N * (N - 1) / 2){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo;
}
