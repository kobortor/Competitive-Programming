#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

int N, S;

ll tot = 0;
ll prefix[MAXN];

ll dist(int a, int b){
    if(a > b){
        swap(a, b);
    }
    return min(prefix[b - 1] - prefix[a - 1], tot - (prefix[b - 1] - prefix[a - 1]));
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> S;
    
    for(int a = 1; a <= N; a++){
        cin >> prefix[a];
        prefix[a] += prefix[a - 1];
    }
    tot = prefix[N];

    int cur = S;
    int L = S == 1 ? N : S - 1;
    int R = S == N ? 1 : S + 1;

    ll ans = 0;

    for(int a = 1; a <= N - 1; a++){
        ll DL = dist(cur, L);
        ll DR = dist(cur, R);

        if(pll(DL, L) <= pll(DR, R)){
            ans += DL;
            cur = L;

            L = L == 1 ? N : L - 1;
        } else {
            ans += DR;
            cur = R;

            R = R == N ? 1 : R + 1;
        }
    }

    cout << ans;
}
