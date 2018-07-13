#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    ll N;
    cin >> N;

    ll blw = 0;
    while((blw + 1) * (blw + 2) / 2 < N){
        blw++;
    }

    cout << N - blw * (blw + 1) / 2;
}
