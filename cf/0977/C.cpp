#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N, K;
int arr[MAXN];

int count(int x){
    int ans = 0;
    for(int a = 0; a < N; a++){
        if(arr[a] <= x) ans++;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    
    for(int a = 0; a < N; a++) cin >> arr[a];

    int lo = 1, hi = 1e9;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int cnt = count(mid);
        if(cnt == K){
            cout << mid;
            return 0;
        } else if(count(mid) < K){
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    if(1 <= lo && lo <= 1e9 && count(lo) == K){
        cout << lo;
    } else {
        cout << -1;
    }
}
