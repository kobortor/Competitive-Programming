#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
string str[4];
int freq[16];
int maxfreq[16];

ll calc(){
    ll ans = 0;
    for(int a = 0; a < 4; a++){
        ll sum = -N;
        for(int b = 0; b < 16; b++){
            if(b & (1 << a)){
                //true
                sum += 2 * freq[b];
            } else {
                sum += 2 * (maxfreq[b] - freq[b]);
            }
        }
        ans += sum * sum;
    }
    return ans;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;
    for(int a = 0; a < 4; a++){
        cin >> str[a];
    }
    for(int a = 0; a < N; a++){
        int st = (str[0][a] == 'T') | ((str[1][a] == 'T') << 1) | ((str[2][a] == 'T') << 2) | ((str[3][a] == 'T') << 3);
        maxfreq[st]++;
    }

    pll best;

    for(int a = 0; a < (1 << 16); a++){
        for(int b = 0; b < 16; b++){
            if(a & (1 << b)){
                freq[b] = maxfreq[b];
            } else {
                freq[b] = 0;
            }
        }
        best = max(best, pll(calc(), a));
    }

    for(int a = 0; a < N; a++){
        int st = (str[0][a] == 'T') | ((str[1][a] == 'T') << 1) | ((str[2][a] == 'T') << 2) | ((str[3][a] == 'T') << 3);
        if(best.second & (1 << st)){
            cout << "T";
        } else {
            cout << "F";
        }
    }
}
