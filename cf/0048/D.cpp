#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int cnt[MAXN];
int ans[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        ans[a] = ++cnt[x];
    }

    for(int a = 2; a < MAXN; a++){
        if(cnt[a] > cnt[a - 1]){
            cout << -1;
            return 0;
        }
    }

    cout << cnt[1] << "\n";
    for(int a = 1; a <= N; a++){
        cout << ans[a] << " ";
    }
}
