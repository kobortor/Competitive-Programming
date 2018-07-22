#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;

const int MAXK = 20005;
const int MAXN = 205;

int dp[MAXK];
pii notes[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for(int a = 0; a < N; a++){
        cin >> notes[a].first;
    }
    for(int a = 0; a < N; a++){
        cin >> notes[a].second;
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;

    int K;
    cin >> K;

    for(int a = 0; a < N; a++){
        int x = min(notes[a].second, K / notes[a].first);
        vector<int> parts;
        int tmp = 1;
        while(tmp <= x){
            parts.push_back(tmp);
            x -= tmp;
            tmp <<= 1;
        }

        if(x){
            parts.push_back(x);
        }

        for(int i : parts){
            for(int b = K; b >= i * notes[a].first; b--){
                dp[b] = min(dp[b], dp[b - i * notes[a].first] + i);
            }
        }
    }

    cout << dp[K];
}
