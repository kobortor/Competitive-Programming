#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1005;

int N, M, Q;

string S, T;

int prefix[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N >> M >> Q >> S >> T;

    for(int a = 0; a < N; a++){
        prefix[a + 1] = prefix[a];

        if(a + M - 1 < N){
            prefix[a + 1]++;
            for(int b = 0; b < M; b++){
                if(T[b] != S[a + b]){
                    prefix[a + 1]--;
                    break;
                }
            }
        }
    }

    while(Q--){
        int l, r;
        cin >> l >> r;

        if(r - l + 1 < M){
            cout << 0 << "\n";
            continue;
        }

        cout << prefix[r - M + 1] - prefix[l - 1] << "\n";
    }
}
