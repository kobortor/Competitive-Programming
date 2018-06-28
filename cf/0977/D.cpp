#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<pair<pll, ll>> vec;

pii get_fac(ll x){
    pll ans = pll(0, 0);
    while(x % 3 == 0) {
        ans.first--;
        x /= 3;
    }
    while(x % 2 == 0) {
        ans.second++;
        x /= 2;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;
    while(N--){
        ll x;
        cin >> x;
        vec.push_back({get_fac(x), x});
    }
    sort(allof(vec));
    for(auto au : vec){
        cout << au.second << " ";
    }
}
