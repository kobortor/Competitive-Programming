#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
const int SQRT = 512;

int N, Q;

vector<int> sieve[MAXN];
int arr[MAXN];
int roger[MAXN][SQRT];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 1; a < MAXN; a++){
        for(int b = a; b < MAXN; b += a){
            sieve[b].push_back(a);
        }
    }

    cin >> N >> Q;
    for(int a = 0; a < N; a++){
        cin >> arr[a];
        for(int i : sieve[arr[a]]){
            roger[i][a / SQRT]++;
        }
    }
    for(int a = 0; a < Q; a++){
        int tp;
        cin >> tp;
        if(tp == 1){
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;

            int sql = (l + SQRT - 1) / SQRT;
            int sqr = r / SQRT;

            int ans = 0;

            if(sql >= sqr){
                for(int a = l; a <= r; a++){
                    if(arr[a] % x == 0){
                        ans++;
                    }
                }
            } else {
                for(int a = sql; a < sqr; a++){
                    ans += roger[x][a];
                }
                for(int a = sql * SQRT - 1; a >= l; a--){
                    if(arr[a] % x == 0){
                        ans++;
                    }
                }
                for(int a = sqr * SQRT; a <= r; a++){
                    if(arr[a] % x == 0){
                        ans++;
                    }               
                }
            }
            cout << ans << "\n";
        } else {
            int u, v;
            cin >> u >> v;
            u--;
            for(int i : sieve[arr[u]]){
                roger[i][u / SQRT]--;
            }
            arr[u] = v;
            for(int i : sieve[arr[u]]){
                roger[i][u / SQRT]++;
            }
        }
    }
    
}
