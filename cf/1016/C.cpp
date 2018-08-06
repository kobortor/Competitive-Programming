#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 3e5 + 5;

int N;
ll grow[MAXN][2];
ll accum[MAXN][2]; //cost if reach end at T = 0, [from top / bottom]
ll prefix[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 1; a <= N; a++){
        cin >> grow[a][0];
    }

    for(int a = 1; a <= N; a++){
        cin >> grow[a][1];
    }

    for(int a = N; a >= 1; a--){
        prefix[a] = prefix[a + 1] + grow[a][0] + grow[a][1];
        accum[a][0] = accum[a + 1][0] - grow[a][0] * (N - a) + grow[a][1] * (N - a + 1);
        accum[a][1] = accum[a + 1][1] - grow[a][1] * (N - a) + grow[a][0] * (N - a + 1);

    }

    ll ans = 0;
    ll back = 0;
    for(int a = 0; a <= N; a++){
        ll time_to_end = 2 * a + N - a - 1;
        ll cost;
        if(a % 2 == 1){
            back += (a * 2 - 2) * grow[a][0];
            back += (a * 2 - 1) * grow[a][1];

            cost = accum[a + 1][1] + prefix[a + 1] * time_to_end;
        } else {
            back += (a * 2 - 2) * grow[a][1];
            back += (a * 2 - 1) * grow[a][0];

            cost = accum[a + 1][0] + prefix[a + 1] * time_to_end;
            ans = max(ans, back + cost);
        }
        ans = max(ans, back + cost);
    }

    cout << ans;
}
