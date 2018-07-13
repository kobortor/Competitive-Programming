#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll N, M;
vector<ll> vec;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M;
    for(int a = 0; a < N; a++){
        ll x;
        cin >> x;
        vec.push_back(x);
    }

    sort(allof(vec));
    vec.push_back(2e9);

    ll sum = 0;

    for(int i = 0; i < (int)vec.size(); i++){
        if(M + i < vec[i]){
            ll tmp = i + M;
            cout << tmp * (tmp + 1) / 2 - sum;
            return 0;
        }
        sum += vec[i];
    }
}
