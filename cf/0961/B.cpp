#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int arr[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }

    int ans = 0;
    int extra = 0;
    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        ans += arr[a] * x;
        arr[a] *= !x;
        arr[a] += arr[a-1];
        if(a >= K){
            extra = max(extra, arr[a] - arr[a-K]);
        }
    }
    cout << ans + extra;

}
