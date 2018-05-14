#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int arr[MAXN];
int tmp[MAXN];

int solve(int p0, int p1){
    memcpy(tmp, arr, sizeof tmp);
    tmp[0] += p0;
    tmp[1] += p1;

    int diff = tmp[1] - tmp[0];
    int cost = abs(p0) + abs(p1);
    for(int a = 2; a < N; a++){
        int targ = tmp[a-1] + diff;
        if(abs(tmp[a] - targ) <= 1){
            cost += abs(tmp[a] - targ);
            tmp[a] = targ;
        } else {
            return 1e9;
        }
    }
    return cost;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
    }
    if(N <= 2){
        cout << 0;
        return 0;
    }

    int ans = 1e9;

    for(int a = -1; a <= 1; a++){
        for(int b = -1; b <= 1; b++){
            ans = min(ans, solve(a, b));
        }
    }
    if(ans == 1e9){
        cout << -1;
    } else {
        cout << ans;
    }
}
