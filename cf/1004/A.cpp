#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N, D;
    cin >> N >> D;

    vector<ll> vec;
    for(int a = 0; a < N; a++){
        ll x;
        cin >> x;
        vec.push_back(x);
    }

    vec.push_back(-1e15);
    vec.push_back(+1e15);

    sort(allof(vec));

    int ans = 0;

    for(int i = 1; i + 1 < (int)vec.size(); i++){
        if(vec[i] - vec[i - 1] > 2 * D){
            ans++;
        }
        if(vec[i + 1] - vec[i] >= 2 * D){
            ans++;
        }
    }

    cout << ans;
}
