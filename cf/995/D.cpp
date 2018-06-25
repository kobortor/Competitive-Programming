#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 18;

int N, R;
ll val[1 << MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> R;

    ll sum = 0;
    for(int a = 0; a < (1 << N); a++){
        cin >> val[a];
        sum += val[a];
    }

    cout << fixed << setprecision(15) << (double)sum / (1 << N) << "\n";
    while(R--){
        ll Z, G;
        cin >> Z >> G;
        sum += G - val[Z];
        val[Z] = G;

        cout << fixed << setprecision(15) << (double)sum / (1 << N) << "\n";
    }
}
