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

    if(N == 0){
        cout << 0;
        return 0;
    }

    N++;

    if(N % 2 == 0){
        cout << N / 2;
    } else {
        cout << N;
    }
}
