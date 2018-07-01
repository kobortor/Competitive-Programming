#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int cnt[6];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int tot = 0;

    cin >> N;
    for(int a = 0; a < N; a++){
        int x;
        cin >> x;

        tot += x;
        cnt[x]++;
    }

    int cur = 2;
    int ans = 0;
    while(tot * 2 < N * 9){
        if(!cnt[cur]){
            cur++;
        } else {
            tot += 5 - cur;
            cnt[cur]--;
            ans++;
        }
    }

    cout << ans;
}
