#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<int> ans;
    for (int a = 0; a < 3; a++) {
        int x, y, z;
        cin >> x >> y >> z;
        int mid = x + y + z - min(x, min(y, z)) - max(x, max(y, z));

        ans.push_back(mid);
    }

    sort(allof(ans));
    cout << ans[1];
}
