#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 505;

bitset<MAXN> bits[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    int N;
    cin >> N;

    for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            char c;
            cin >> c;
            bits[a][b] = (c == '1');
        }
    }

    for(int k = 0; k < N; k++){
        for(int a = 0; a < N; a++){
            if(bits[a][k]){
                bits[a] |= bits[k];
            }
        }
    }

    int ans = 0;
    for(int a = 0; a < N; a++){
        for(int b = a + 1; b < N; b++){
            if(!bits[a][b] && !bits[b][a]){
                ans++;
            }
        }
    }

    cout << ans << endl;
}
