#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool good(int x){
    int div = 0;
    for(int a = 1; a <= x; a++){
        div += (x % a == 0);
    }
    return div == 8;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    int ans = 0;
    for(int a = 1; a <= N; a += 2){
        ans += good(a);
    }

    cout << ans;
}
