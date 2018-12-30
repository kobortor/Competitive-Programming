#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> factorize(int n){
    vector<int> ans;
    for(int a = 1; a * a <= n; a++){
        if(n % a == 0) {
            ans.push_back(a);
            ans.push_back(n / a);
        }
    }

    sort(allof(ans));
    ans.erase(unique(allof(ans)), ans.end());

    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> factors = factorize(N);

    vector<ll> soln;
    for(int i : factors){
        ll steps = N / i;
        ll nc2 = steps * (steps - 1) / 2;
        ll ans = steps + i * nc2;
        soln.push_back(ans);
    }
    sort(allof(soln));
    soln.erase(unique(allof(soln)), soln.end());

    for(ll x : soln){
        cout << x << " ";
    }
}
