#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, K;
    string S;
    
    cin >> N >> K >> S;

    if(count(allof(S), '1') == 0){
        cout << (ll)N * K;
        return 0;
    }
    
    if(K != 1){
        S += S;
        N += N;
    }

    int ans = 0;
    for(int a = 0, b = 0; a < N; a++){
        if(S[a] == '1'){
            b = a + 1;
        }
        ans = max(ans, a - b + 1);
    }
    cout << ans;
}
