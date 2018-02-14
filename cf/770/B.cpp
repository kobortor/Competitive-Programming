#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll POW10[20];

int sum(string str){
    int ans = 0;
    for(char c : str){
        ans += c - '0';
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    POW10[0] = 1;
    for(int a = 1; a < 20; a++){
        POW10[a] = POW10[a - 1] * 10;
    }

    ll val;
    cin >> val;

    pll best = pll(sum(to_string(val)), val);

    for(int a = 1; POW10[a] <= val && a <= 18; a++){
        ll nv = (val / POW10[a] - 1) * POW10[a] + POW10[a] - 1;
        best = max(best, pll(sum(to_string(nv)), nv));
    }
    cout << best.second;
}
