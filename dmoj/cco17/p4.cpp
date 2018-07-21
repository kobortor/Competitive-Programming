#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 501;
const int MAXH = 51;

int N;
int freq[MAXH];

bitset<MAXN * MAXH> dp[MAXN];
bitset<MAXN * MAXH> tmp[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int last = 0;

    cin >> N;
    while(N--){
        int x;
        cin >> x;
        freq[x]++;
        last = max(last, x);
    }

    freq[last]--;
    dp[0][0] = true;

    for(int a = last; a >= 1; a--){
        if(freq[a] == 0){
            continue;
        }

        for(int b = 0; b <= freq[a]; b++){
            tmp[0] |= dp[b] >> (a * b);
        }

        for(int b = 1; b < MAXN; b++){
            tmp[b] = tmp[b - 1] << a;
            if(b + freq[a] < MAXN){
                tmp[b] |= dp[b + freq[a]] >> (a * freq[a]);
            }
        }

        memcpy(dp, tmp, sizeof tmp);
        memset(tmp, 0, sizeof tmp);
    }

    for(int a = 0; a < MAXN * MAXH; a++){
        if(dp[0][a]){
            cout << a << " ";
        }
    }
}
