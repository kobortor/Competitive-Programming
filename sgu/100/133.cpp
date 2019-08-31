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

    vector<pii> outposts(n);
    for (pii &p : outposts) cin >> p.first >> p.second;

    sort(allof(outposts));

    int rightmost = -1;
    int ans = 0;

    for (int a = 0; a < n; a++) {
        if (outposts[a].second < rightmost) ans++;
        rightmost = max(rightmost, outposts[a].second);
    }

    cout << ans;
}
