#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2005;

int N, K;
vector<pii> probs;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;
    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        probs.push_back({x, a});
    }

    sort(allof(probs));
    reverse(allof(probs));

    vector<int> ans;
    ans.push_back(0);
    int tot = 0;

    for(int a = 0; a < K; a++){
        tot += probs[a].first;
        ans.push_back(probs[a].second);
    }

    sort(allof(ans));
    ans.back() = N;

    cout << tot << "\n";
    for(int a = 1; a <= K; a++){
        cout << ans[a] - ans[a - 1] << " ";
    }
}
