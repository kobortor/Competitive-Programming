#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


const int MAXN = 1e5 + 5;

int T;
int deg[MAXN];

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> T;
    while(T--){
        memset(deg, 0, sizeof deg);
        
        int N, M;
        cin >> N >> M;
        for(int a = 0; a < M; a++){
            int x, y;
            cin >> x >> y;
            deg[x]++;
            deg[y]++;
        }
        int numeven = 0;
        for(int a = 1; a <= N; a++) {
            if(deg[a] % 2 == 0){
                numeven++;
            }
        }
        cout << numeven % 2 << "\n";
    }
}