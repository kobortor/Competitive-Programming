#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, A, B, C, T;
    cin >> N >> A >> B >> C >> T;

    int ans = A * N;
    while(N--){
        int x;
        cin >> x;
        ans += max(0, (T - x) * (C - B));
    }
    cout << ans;
}
