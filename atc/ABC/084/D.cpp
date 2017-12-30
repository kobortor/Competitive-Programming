#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5 + 5;

bool sieve[MAXN];
int good[MAXN];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    sieve[1] = true;
    for(int a = 2; a < MAXN; a++){
        if(!sieve[a]){
            for(int b = 2 * a; b < MAXN; b += a){
                sieve[b] = true;
            }
        }
    }
    for(int a = 1; a < MAXN; a++) {
        good[a] += good[a - 1];
        if(a % 2 == 1 && !sieve[a] && !sieve[(a + 1) / 2]){
            good[a]++;
        }
    }
    int Q;
    cin >> Q;

    while(Q--){
        int L, R;
        cin >> L >> R;
        cout << good[R] - good[L - 1] << "\n";
    }
}