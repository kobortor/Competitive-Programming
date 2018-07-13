#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

int _[21];
int *T = _ + 10;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll ans = 0;

    cin >> N;
    while(N--){
        int x;
        cin >> x;

        ans += T[-x];

        T[x]++;
    }

    cout << ans;
}
