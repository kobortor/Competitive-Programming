#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N, K;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> K;

    vector<int> lodges;

    for(int a = 1; a <= N; a++){
        int x;
        cin >> x;
        if(x){
            lodges.push_back(a);
        }
    }

    int ans = 0;
    int cur = 0;
    while(lodges[cur] != N){
        int nxt = cur;
        while(lodges[nxt] != N && lodges[nxt + 1] - lodges[cur] <= K){
            nxt++;
        }

        if(cur == nxt){
            cout << -1;
            return 0;
        }

        cur = nxt;
        ans++;
    }

    cout << ans;
}
