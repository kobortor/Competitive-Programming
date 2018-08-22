#include<bits/stdc++.h>

using namespace std;

#define allof(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e6 + 6;

vector<ll> primes;
bool sieve[MAXN];
vector<pll> check(ll K, ll M){
    vector<pll> ret;
    for(ll p : primes){
        ll prod = 0;
        while(K % p == 0){
            K /= p;
            prod++;
        }
        prod *= M;
        if(prod){
            ret.push_back({p, prod});
        }
    }
    return ret;
}

void testcase(){
    ll K, M;
    cin >> K >> M;
    vector<pll> fac = check(K, M);

    ll lo = 2, hi = 1e18;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        bool good = true;
        for(pll p : fac){
            ll tmp = p.first;
            ll cnt = 0;
            while(tmp < 5e12){
                cnt += mid / tmp;
                tmp *= p.first;
            }

            if(cnt < p.second){
                good = false;
            }
        }
        if(good){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    freopen("DATA31.txt", "r", stdin);

    for(int a = 2; a < MAXN; a++){
        if(!sieve[a]){
            primes.push_back(a);
            for(int b = 2 * a; b < MAXN; b += a){
                sieve[b] = true;
            }
        }
    }

    const int MAX_CASE = 10;
    for(int a = 1; a <= MAX_CASE; a++){
        testcase();
    }
}
