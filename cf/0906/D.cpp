#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int MAXP = sqrt(1e9) + 10;

bool notprime[MAXP];
vector<int> primes;

//just for speedup
map<int, int> stored_tot;

int totient(int X){
    int orig = X;
    int &ans = stored_tot[X];
    if(ans != 0) {
        return ans;
    }
    vector<int> factors;
    for(int i : primes){
        if(i > X){
            break;
        }
        if(X % i == 0){
            factors.push_back(i);
            while(X % i == 0){
                X /= i;
            }
        }
    }
    if(X != 1){
        factors.push_back(X);
    }
    for(int i : factors){
        orig = orig / i * (i - 1);
    }
    return ans = orig;
}

//<ans, modded>
pair<ll, bool> qpow(ll x, ll y, ll M){
    if(!y) {
        return {1 % M, M == 1};
    }

    bool modded;
    ll tmp;
    tie(tmp, modded) = qpow(x, y / 2, M);

    tmp = tmp * tmp;

    if(tmp >= M){
        modded = true;
        tmp %= M;
    }

    if(y & 1){
        tmp = tmp * x;
        if(tmp >= M){
            modded = true;
            tmp %= M;
        }
    }
    return {tmp, modded};
}

int gcd(int a, int b) {
    while(a % b) {
        a %= b;
        swap(a, b);
    }
    return b;
}

ll arr[MAXN];

//<ans, modded>
pair<ll, bool> solve(ll L, ll R, ll M){
    //arr[L] ^ totient(M) is equiv to 1 mod M iff they are coprime
    //otherwise, arr[L]^N is equiv to arr^(N + totient(M)) mod M
    //so the first [0, totient(M) - 1] range is different from the ones later

    if(M == 1){
        return {0, true};
    }
    if(M == 2){
        return {arr[L] % M, arr[L] >= M};
    }
    if(L == R){
        return {arr[L] % M, arr[L] >= M};
    }

    ll tot = totient(M);

    pair<ll, bool> slv = solve(L + 1, R, tot);
    pair<ll, bool> power = qpow(arr[L] % M, slv.first + slv.second * tot, M);
    power.second |= arr[L] >= M;
    return power;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);

    for(int a = 2; a < MAXP; a++){
        if(!notprime[a]){
            primes.push_back(a);
            for(int b = 2 * a; b < MAXP; b += a){
                notprime[b] = true;
            }
        }
    }

    int N, M;
    cin >> N >> M;
    for(int a = 1; a <= N; a++){
        cin >> arr[a];
    }
    int Q;
    cin >> Q;
    while(Q--){
        int l, r;
        cin >> l >> r;
        cout << solve(l, r, M).first % M << "\n";
    }
}