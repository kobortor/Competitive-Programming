#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    vector<int> money, games;

    int N, M;
    cin >> N >> M;

    while(N--){
        int c;
        cin >> c;
        games.push_back(c);
    }

    while(M--){
        int x;
        cin >> x;
        money.push_back(x);
    }

    money.push_back(-1);

    reverse(allof(money));

    int ans = 0;
    for(int i : games){
        if(money.back() >= i){
            money.pop_back();
            ans++;
        }
    }

    cout << ans;
}
