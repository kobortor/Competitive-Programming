#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int SQRT = 1e6 + 6;

bitset<SQRT> sieve;
vector<ll> primes;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    for(int a = 2; a < SQRT; a++){
        if(!sieve[a]){
            primes.push_back(a);
            for(int b = 2 * a; b < SQRT; b += a){
                sieve[b] = true;
            }
        }
    }

    int T;
    cin >> T;
    while(T--){
        ll N;
        cin >> N;

        ll ans = 0;
        while(N > 1){
            ll nxt = 0;
            int nprimes = 0;
            for(ll p : primes){
                if(N % p == 0){
                    ans++;
                    nxt += p;
                }
                while(N % p == 0){
                    nprimes++;
                    N /= p;
                }
            }
            if(nprimes == 0){
                ans++;
                break;
            }
            if(nprimes == 1 && N == 1){
                break;
            }
            if(N != 1){
                ans++;
                nxt += N;
            }
            N = nxt;
        }
        cout << ans << "\n";
    }

}
