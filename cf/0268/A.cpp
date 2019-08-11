#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;

    vector<pii> teams;
    int ans = 0;
    for (int a = 0; a < n; a++) {
        int hi, ai;
        cin >> hi >> ai;
        for (pii p : teams) {
            if (p.first == ai) ans++;
            if (p.second == hi) ans++;
        }
        teams.push_back({hi, ai});
    }

    cout << ans;
}
