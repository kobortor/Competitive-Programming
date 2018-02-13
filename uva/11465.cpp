#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
ll lengths[35];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int test = 1; test <= N; test++){
        int N, K;
        cin >> N >> K;

        for(int a = 0; a < N; a++){
            cin >> lengths[a];
        }
        sort(lengths, lengths + N);

        ll ans = 0;

        for(int a = 2; a < N; a++){
            vector<ll> sticks[2];
            for(int b = 0; b < a; b++){
                sticks[b % 2].push_back(lengths[b]);
            }
            vector<ll> sums[2][16];
            for(int i = 0; i < 2; i++){
                for(int b = 0; b < (1 << sticks[i].size()); b++){
                    ll cnt = 0, val = 0;
                    for(int c = 0; c < (int)sticks[i].size(); c++){
                        if(b & (1 << c)){
                            cnt++;
                            val += sticks[i][c];
                        }
                    }
                    sums[i][cnt].push_back(val);
                }
                for(int b = 0; b <= (int)sticks[i].size(); b++){
                    sort(allof(sums[i][b]));
                }
            }
            for(int b = 0; b <= (int)sticks[0].size(); b++){
                ll inv = K - 1 - b;
                if(0 <= inv && inv <= 15){
                    for(ll v : sums[0][b]){
                        ll atleast = lengths[a] - v + 1;
                        ll added = sums[1][inv].end() - lower_bound(allof(sums[1][inv]), atleast);
                        ans += added;
                    }
                }
            }
        }
        cout << "Case " << test << ": " << ans << endl;
    }
}
