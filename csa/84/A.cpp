#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 305;

int N, W;
pii spots[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> W;
    for(int a = 1; a <= N; a++){
        cin >> spots[a].first >> spots[a].second;
    }

    for(int a = 1; a <= N; a++){
        if(spots[a].first == 1){
            int tot = 0;
            int b = a - 1;
            while(b + 1 <= N && spots[b + 1].first == 1){
                b++;
                tot += spots[b].second;
            }

            if(tot >= W){
                cout << a;
                return 0;
            }
        }
    }

    cout << -1;
}
