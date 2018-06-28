#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;
    for(ll a = 1; a <= K; a++){
        if(N % a != a - 1){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
