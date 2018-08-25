#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K;
vector<int> L, R;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    cin >> N >> K;
    while(N--){
        int x;
        cin >> x;
        if(x <= 0){
            L.push_back(-x);
        } else {
            R.push_back(x);
        }
    }

    reverse(allof(L));

    int ans = 2e9;
    if((int)L.size() >= K){
        ans = L[K - 1];
    }

    if((int)R.size() >= K){
        ans = R[K - 1];
    }

    for(int a = 0; a < (int)L.size() && a < K - 1; a++){
        if(K - a - 2 < (int)R.size()){
            ans = min(ans, L[a] * 2 + R[K - a - 2]);
        }
    }

    for(int a = 0; a < (int)R.size() && a < K - 1; a++){
        if(K - a - 2 < (int)L.size()){
            ans = min(ans, R[a] * 2 + L[K - a - 2]);
        }
    }

    cout << ans;
}
