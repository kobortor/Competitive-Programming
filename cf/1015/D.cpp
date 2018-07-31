#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, K, S;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K >> S;
    
    if(S < K || S > (N - 1) * K){
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    int cur = 1;
    while(K--){
        int extra = min(S - K, N - 1);
        if(cur - extra >= 1){
            cur -= extra;
        } else {
            cur += extra;
        }
        S -= extra;
        cout << cur << " ";
    }
}
