#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, L, A;

pii customer[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> L >> A;

    for(int a = 1; a <= N; a++){
        cin >> customer[a].first;
        cin >> customer[a].second;
        customer[a].second += customer[a].first;
    }

    int ans = 0;
    if(N){
        ans += customer[1].first / A;
        ans += (L - customer[N].second) / A;
    } else {
        ans += L / A;
    }

    for(int a = 1; a < N; a++){
        ans += (customer[a + 1].first - customer[a].second) / A;
    }

    cout << ans;
}
