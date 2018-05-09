#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

ll N, K;
ll soldier[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    for(int a = 1; a <= N; a++){
        cin >> soldier[a];
        soldier[a] += soldier[a-1];
    }

    ll tot = 0;
    while(K--){
        ll arrow;
        cin >> arrow;
        tot += arrow;
        if(tot >= soldier[N]){
            tot = 0;
            cout << N << "\n";
        } else {
            cout << (soldier + N + 1) - upper_bound(soldier, soldier + N + 1, tot) << "\n";
        }
    }
}
