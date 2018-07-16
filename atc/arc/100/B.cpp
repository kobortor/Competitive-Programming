#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int N;
ll arr[MAXN];

ll cost(int l, int r){
    return arr[r] - arr[l - 1];
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
        arr[a] += arr[a - 1];
    }

    ll ans = 1e18;
    for(int a = 2, ml = 1, mr = 3; a <= N - 2; a++){
        //[1...ml][ml+1...a][a+1...mr][mr+1...N]

        while(ml + 1 < a && abs(cost(1, ml + 1) - cost(ml + 2, a)) <= abs(cost(1, ml) - cost(ml + 1, a))){
            ml++;
        }

        mr = max(a, mr);
        while(mr + 1 < N && abs(cost(a + 1, mr + 1) - cost(mr + 2, N)) <= abs(cost(a + 1, mr) - cost(mr + 1, N))){
            mr++;
        }

        ll A = cost(1, ml), B = cost(ml + 1, a), C = cost(a + 1, mr), D = cost(mr + 1, N);

        ans = min(ans, max(max(A, B), max(C, D)) - min(min(A, B), min(C, D)));
    }
    cout << ans;
}
