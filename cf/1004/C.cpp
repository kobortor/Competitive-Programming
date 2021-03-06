#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N;
int prv[MAXN];
bool first[MAXN];
bool last[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;

        if(prv[x]){
            last[prv[x]] = false;
        } else {
            first[a] = true;
        }

        prv[x] = a;
        last[a] = true;
    }

    ll ans = 0;
    for(int a = 1, cnt = 0; a <= N; a++){
        if(last[a]){
            ans += cnt;
        }
        cnt += (first[a]);
    }

    cout << ans;
}
